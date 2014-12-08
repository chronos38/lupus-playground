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
#ifndef LUPUS_DATE_H
#define LUPUS_DATE_H
#ifdef _MSC_VER
#pragma once
#endif

#include "Configuration.h"
#include <SFML/System/String.hpp>
#include <SFML/System/Time.hpp>
#include <ctime>

namespace sf {
    enum WeekDay {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    enum class DateKind {
        Unspecified,
        Local,
        Utc
    };

    class LUPUS_CORE_API Date
    {
    public:
        Date();
        Date(const Date&) = default;
        Date(Date&&);
        Date(Int64 ticks);
        Date(Int32 year, Int32 month, Int32 day);
        Date(Int32 year, Int32 month, Int32 day, DateKind kind);
        Date(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second);
        Date(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, DateKind kind);
        ~Date() = default;

        Int64 getTicks() const;
        void setTicks(Int64 value);
        Int32 getYear() const;
        void setYear(Int32 value);
        Int32 getMonth() const;
        void setMonth(Int32 value);
        Int32 getDay() const;
        void setDay(Int32 day);
        Int32 getHour() const;
        void setHour(Int32 hour);
        Int32 getMinute() const;
        void setMinute(Int32 minute);
        Int32 getSecond() const;
        void setSecond(Int32 second);
        WeekDay getDayOfWeek() const;
        Int32 getDayOfYear() const;
        Time getTimeOfDay() const;

        Date add(const Time& value) const;
        Date addTicks(Int64 value) const;
        Date addYears(Int32 value) const;
        Date addMonths(Int32 value) const;
        Date addDays(double value) const;
        Date addHours(double value) const;
        Date addMinutes(double value) const;
        Date addSeconds(Int32 value) const;
        Date subtract(const Time& value) const;
        Time subtract(const Date& value) const;

        Date& operator=(const Date&) = default;
        Date& operator=(Date&&);
        bool operator==(const Date&) const;
        bool operator!=(const Date&) const;
        bool operator<(const Date&) const;
        bool operator<=(const Date&) const;
        bool operator>(const Date&) const;
        bool operator>=(const Date&) const;
        Date operator+(const Time& value) const;
        Date operator-(const Time& value) const;
        Time operator-(const Date& value) const;
        Date& operator+=(const Time& value);
        Date& operator-=(const Time& value);

        String toString() const;
        String toString(String format) const;

        static Date Now();
        static Date UtcNow();

    private:
        Date(std::tm&&);
        mutable std::tm mTime;
    };

    LUPUS_CORE_API Date operator+(const Time&, const Date&);
    LUPUS_CORE_API Date operator-(const Time&, const Date&);
    LUPUS_CORE_API String toString(const Date&);
}

#endif
