/**
 * Copyright (C) 2014 David Wolf <d.wolf@live.at>
 *
 * This file is part of Lupus.
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "Date.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <cmath>

using stringstream = std::stringstream;

#ifndef _MSC_VER
#include <time.h>
#define localtime_s(tm, time) localtime_r(time, tm)
#define gmtime_s(tm, time) gmtime_r(time, tm)
#endif

namespace sf {
    Date::Date(Date&& date)
    {
        mTime = std::move(date.mTime);
    }

    Date::Date(Int64 ticks)
    {
        auto value = static_cast<std::time_t>(ticks);
        localtime_s(&mTime, &value);
    }

    Date::Date(Int32 year, Int32 month, Int32 day) :
        Date(year, month, day, 0, 0, 0, DateKind::Unspecified)
    {
    }

    Date::Date(Int32 year, Int32 month, Int32 day, DateKind kind) :
        Date(year, month, day, 0, 0, 0, kind)
    {
    }

    Date::Date(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second) :
        Date(year, month, day, hour, minute, second, DateKind::Unspecified)
    {
    }

    Date::Date(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateKind kind)
    {
        {
            std::time_t time;

            switch (kind) {
            case DateKind::Unspecified:
                memset(&mTime, 0, sizeof(mTime));
                mTime.tm_isdst = -1;
                break;

            case DateKind::Utc:
                std::time(&time);
                gmtime_s(&mTime, &time);
                break;

            case DateKind::Local:
                std::time(&time);
                localtime_s(&mTime, &time);
                break;
            }
        }

        mTime.tm_year = year - 1900;
        mTime.tm_mon = month - 1;
        mTime.tm_mday = day;
        mTime.tm_hour = hour;
        mTime.tm_min = minute;
        mTime.tm_sec = second;
        mktime(&mTime);
    }

    Date::Date(std::tm&& value)
    {
        mTime = std::move(value);
        mktime(&mTime);
    }

    Int64 Date::getTicks() const
    {
        return static_cast<Int64>(mktime(&mTime));
    }

    Int32 Date::getYear() const
    {
        return mTime.tm_year + 1900;
    }
    
    Int32 Date::getMonth() const
    {
        return mTime.tm_mon + 1;
    }
    
    Int32 Date::getDay() const
    {
        return mTime.tm_mday;
    }
    
    Int32 Date::getHour() const
    {
        return mTime.tm_hour;
    }
    
    Int32 Date::getMinute() const
    {
        return mTime.tm_min;
    }
    
    Int32 Date::getSecond() const
    {
        return mTime.tm_sec;
    }
    
    WeekDay Date::getDayOfWeek() const
    {
        switch (mTime.tm_wday) {
        case 1:
            return Monday;
        case 2:
            return Tuesday;
        case 3:
            return Wednesday;
        case 4:
            return Thursday;
        case 5:
            return Friday;
        case 6:
            return Saturday;
        default:
            return Sunday;
        }
    }
    
    Int32 Date::getDayOfYear() const
    {
        return mTime.tm_yday;
    }

    Time Date::getTimeOfDay() const
    {
        return milliseconds(
            getHour() * 60 * 60 * 1000 +
            getMinute() * 60 * 1000 +
            getSecond() * 1000
        );
    }

    Date Date::add(const Time& value) const
    {
        auto result = mTime;
        result.tm_sec += static_cast<int>(std::floor(value.asSeconds()));
        return Date(std::move(result));
    }
    
    Date Date::addTicks(Int64 value) const
    {
        return Date(mktime(&mTime) + value);
    }
    
    Date Date::addYears(Int32 value) const
    {
        return Date(getYear() + value, getMonth(), getDay(), getHour(), getMinute(), getSecond());
    }
    
    Date Date::addMonths(Int32 value) const
    {
        return Date(getYear(), getMonth() + value, getDay(), getHour(), getMinute(), getSecond());
    }
    
    Date Date::addDays(double value) const
    {
        auto day = (Int32)value;
        auto hour = (value - std::floor(value)) * 24;
        auto minute = (hour - std::floor(hour)) * 60;
        auto second = (minute - std::floor(minute)) * 60;
        return Date(getYear(), getMonth(), getDay() + day, getHour() + (Int32)hour, getMinute() + (Int32)minute, getSecond() + (Int32)second);
    }
    
    Date Date::addHours(double value) const
    {
        return addDays(value / 24);
    }
    
    Date Date::addMinutes(double value) const
    {
        return addHours(value / 60);
    }
    
    Date Date::addSeconds(double value) const
    {
        return addMinutes(value / 60);
    }
    
    Date Date::subtract(const Time& value) const
    {
        auto result = mTime;
        result.tm_sec -= static_cast<int>(std::floor(value.asSeconds()));
        return Date(std::move(result));
    }
    
    Time Date::subtract(const Date& value) const
    {
        return seconds((float)std::difftime(mktime(&mTime), mktime(&value.mTime)));
    }

    Date& Date::operator=(Date&& date)
    {
        mTime = std::move(date.mTime);
        return *this;
    }

    bool Date::operator==(const Date& date) const
    {
        return getTicks() == date.getTicks();
    }

    bool Date::operator!=(const Date& date) const
    {
        return getTicks() != date.getTicks();
    }

    bool Date::operator<=(const Date& date) const
    {
        return getTicks() <= date.getTicks();
    }

    bool Date::operator<(const Date& date) const
    {
        return getTicks() < date.getTicks();
    }

    bool Date::operator>=(const Date& date) const
    {
        return getTicks() >= date.getTicks();
    }

    bool Date::operator>(const Date& date) const
    {
        return getTicks() > date.getTicks();
    }

    Date Date::operator+(const Time& time) const
    {
        auto result = mTime;
        result.tm_sec += static_cast<int>(std::floor(time.asSeconds()));
        return Date(std::move(result));
    }

    Time Date::operator+(const Date& date) const
    {
        return seconds((float)std::difftime(mktime(&mTime), (-1) * mktime(&date.mTime)));
    }

    Date Date::operator-(const Time& time) const
    {
        auto result = mTime;
        result.tm_sec -= static_cast<int>(std::floor(time.asSeconds()));
        return Date(std::move(result));
    }

    Time Date::operator-(const Date& date) const
    {
        return seconds((float)std::difftime(mktime(&mTime), mktime(&date.mTime)));
    }

    String Date::toString() const
    {
        stringstream ss;
        ss << std::put_time(&mTime, "%c");
        return ss.str();
    }

    String Date::toString(const String& format) const
    {
        stringstream ss;
        ss << std::put_time(&mTime, format.toAnsiString().c_str());
        return ss.str();
    }

    Date Date::Now()
    {
        auto time = std::time(NULL);
        Date result;
        localtime_s(&result.mTime, &time);
        return result;
    }

    Date Date::UtcNow()
    {
        auto time = std::time(NULL);
        Date result;
        gmtime_s(&result.mTime, &time);
        return result;
    }

    Date operator+(const Time& lhs, const Date& rhs)
    {
        std::tm result;
        memset(&result, 0, sizeof(result));
        result.tm_year = rhs.getYear() - 1900;
        result.tm_mon = rhs.getMonth() - 1;
        result.tm_mday = rhs.getDay();
        result.tm_hour = rhs.getHour();
        result.tm_min = rhs.getMinute();
        result.tm_sec = rhs.getSecond();
        result.tm_isdst = -1;

        result.tm_sec += static_cast<int>(std::floor(lhs.asSeconds()));
        return Date(mktime(&result));
    }
    
    Date operator-(const Time& lhs, const Date& rhs)
    {
        std::tm result;
        memset(&result, 0, sizeof(result));
        result.tm_year = rhs.getYear() - 1900;
        result.tm_mon = rhs.getMonth() - 1;
        result.tm_mday = rhs.getDay();
        result.tm_hour = rhs.getHour();
        result.tm_min = rhs.getMinute();
        result.tm_sec = rhs.getSecond();
        result.tm_isdst = -1;

        result.tm_sec -= static_cast<int>(std::floor(lhs.asSeconds()));
        return Date(mktime(&result));
    }

    String toString(const Date& date)
    {
        return date.toString();
    }
}
