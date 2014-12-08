#include <BlackWolf.Lupus.Core/Date.h>
#include <gtest/gtest.h>

using namespace sf;

#ifndef _MSC_VER
#define localtime_s(tm, time) localtime_r(time, tm)
#define gmtime_s(tm, time) gmtime_r(time, tm)
#endif

TEST(Date, constructorTicks)
{
    // Arrange
    auto time = std::time(NULL);
    auto date = Date(time);
    std::tm tm;

    // Act
    localtime_s(&tm, &time);

    // Assert
    ASSERT_EQ(date.getYear(), tm.tm_year + 1900);
    ASSERT_EQ(date.getMonth(), tm.tm_mon + 1);
    ASSERT_EQ(date.getDay(), tm.tm_mday);
    ASSERT_EQ(date.getHour(), tm.tm_hour);
    ASSERT_EQ(date.getMinute(), tm.tm_min);
    ASSERT_EQ(date.getSecond(), tm.tm_sec);

    ASSERT_EQ(date.getDayOfWeek(), tm.tm_wday);
    ASSERT_EQ(date.getDayOfYear(), tm.tm_yday);
}

TEST(Date, constructorIntegerUnspecified)
{
    // Arrange
    auto date = Date(2000, 1, 1, 1, 1, 1, DateKind::Unspecified);

    // Act

    // Assert
    ASSERT_EQ(date.getYear(), 2000);
    ASSERT_EQ(date.getMonth(), 1);
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getHour(), 1);
    ASSERT_EQ(date.getMinute(), 1);
    ASSERT_EQ(date.getSecond(), 1);
}

TEST(Date, constructorIntegerLocal)
{
    // Arrange
    auto date = Date(2000, 1, 1, 1, 1, 1, DateKind::Local);

    // Act

    // Assert
    ASSERT_EQ(date.getYear(), 2000);
    ASSERT_EQ(date.getMonth(), 1);
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getHour(), 1);
    ASSERT_EQ(date.getMinute(), 1);
    ASSERT_EQ(date.getSecond(), 1);
}

TEST(Date, constructorIntegerUtc)
{
    // Arrange
    auto date = Date(2000, 1, 1, 1, 1, 1, DateKind::Utc);

    // Act

    // Assert
    ASSERT_EQ(date.getYear(), 2000);
    ASSERT_EQ(date.getMonth(), 1);
    ASSERT_EQ(date.getDay(), 1);
    ASSERT_EQ(date.getHour(), 1);
    ASSERT_EQ(date.getMinute(), 1);
    ASSERT_EQ(date.getSecond(), 1);
}

TEST(Date, constructorInvalidZero)
{
    EXPECT_THROW({
        auto date = Date(0, 0, 0, 0, 0, 0, DateKind::Unspecified);
    }, std::range_error);
}

TEST(Date, constructorInvalidMax)
{
    EXPECT_THROW({
        auto date = Date(std::numeric_limits<Int32>::max(), 0, 0, 0, 0, 0, DateKind::Unspecified);
    }, std::range_error);
}

TEST(Date, constructorInvalidMin)
{
    EXPECT_THROW({
        auto date = Date(std::numeric_limits<Int32>::min(), 0, 0, 0, 0, 0, DateKind::Unspecified);
    }, std::range_error);
}

TEST(Date, constructorVarious)
{
    EXPECT_NO_THROW({
        Date(2000, 1, 1);
    });
    EXPECT_NO_THROW({
        Date(2000, 1, 1, DateKind::Unspecified);
    });
    EXPECT_NO_THROW({
        Date(2000, 1, 1, 1, 1, 1);
    });
}

TEST(Date, getterSetterInRange)
{
    // Arrange
    Date date;

    // Act
    date.setYear(2000);
    date.setMonth(12);
    date.setDay(31);
    date.setHour(23);
    date.setMinute(59);
    date.setSecond(59);

    // Assert
    ASSERT_EQ(2000, date.getYear());
    ASSERT_EQ(12, date.getMonth());
    ASSERT_EQ(31, date.getDay());
    ASSERT_EQ(23, date.getHour());
    ASSERT_EQ(59, date.getMinute());
    ASSERT_EQ(59, date.getSecond());
}

TEST(Date, getterSetterOutOfRange)
{
    // Arrange
    auto date = Date(2000, 12, 31, 23, 59, 59, DateKind::Unspecified);

    // Act
    date.setSecond(60);

    // Assert
    ASSERT_EQ(2001, date.getYear());
    ASSERT_EQ(1, date.getMonth());
    ASSERT_EQ(1, date.getDay());
    ASSERT_EQ(0, date.getHour());
    ASSERT_EQ(0, date.getMinute());
    ASSERT_EQ(0, date.getSecond());
}

TEST(Date, add)
{
    // Arrange
    auto date = Date(2000, 12, 31, 23, 59, 59, DateKind::Unspecified);

    // Act
    auto result = date.add(seconds(1));

    // Assert
    ASSERT_EQ(2001, result.getYear());
    ASSERT_EQ(1, result.getMonth());
    ASSERT_EQ(1, result.getDay());
    ASSERT_EQ(0, result.getHour());
    ASSERT_EQ(0, result.getMinute());
    ASSERT_EQ(0, result.getSecond());
}

TEST(Date, addYears)
{
    // Arrange
    auto date = Date(2000, 12, 31, 23, 59, 59, DateKind::Unspecified);

    // Act
    auto result = date.addYears(1);

    // Assert
    ASSERT_EQ(2001, result.getYear());
    ASSERT_EQ(12, result.getMonth());
    ASSERT_EQ(31, result.getDay());
    ASSERT_EQ(23, result.getHour());
    ASSERT_EQ(59, result.getMinute());
    ASSERT_EQ(59, result.getSecond());
}

TEST(Date, addMonths)
{
    // Arrange
    auto date = Date(2000, 12, 31, 23, 59, 59, DateKind::Unspecified);

    // Act
    auto result = date.addMonths(1);

    // Assert
    ASSERT_EQ(2001, result.getYear());
    ASSERT_EQ(1, result.getMonth());
    ASSERT_EQ(31, result.getDay());
    ASSERT_EQ(23, result.getHour());
    ASSERT_EQ(59, result.getMinute());
    ASSERT_EQ(59, result.getSecond());
}

TEST(Date, addDays)
{
    // Arrange
    auto date = Date(2000, 12, 31, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto result = date.addDays(1.5);

    // Assert
    ASSERT_EQ(2001, result.getYear());
    ASSERT_EQ(1, result.getMonth());
    ASSERT_EQ(1, result.getDay());
    ASSERT_EQ(12, result.getHour());
    ASSERT_EQ(0, result.getMinute());
    ASSERT_EQ(0, result.getSecond());
}

TEST(Date, addHours)
{
    // Arrange
    auto date = Date(2000, 12, 31, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto result = date.addHours(1.25);

    // Assert
    ASSERT_EQ(2000, result.getYear());
    ASSERT_EQ(12, result.getMonth());
    ASSERT_EQ(31, result.getDay());
    ASSERT_EQ(1, result.getHour());
    ASSERT_EQ(15, result.getMinute());
    ASSERT_EQ(0, result.getSecond());
}

TEST(Date, addMinutes)
{
    // Arrange
    auto date = Date(2000, 12, 31, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto result = date.addMinutes(1.1);

    // Assert
    ASSERT_EQ(2000, result.getYear());
    ASSERT_EQ(12, result.getMonth());
    ASSERT_EQ(31, result.getDay());
    ASSERT_EQ(0, result.getHour());
    ASSERT_EQ(1, result.getMinute());
    ASSERT_EQ(6, result.getSecond());
}

TEST(Date, addSeconds)
{
    // Arrange
    auto date = Date(2000, 12, 31, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto result = date.addSeconds(2);

    // Assert
    ASSERT_EQ(2000, result.getYear());
    ASSERT_EQ(12, result.getMonth());
    ASSERT_EQ(31, result.getDay());
    ASSERT_EQ(0, result.getHour());
    ASSERT_EQ(0, result.getMinute());
    ASSERT_EQ(2, result.getSecond());
}

TEST(Date, subtractTime)
{
    // Arrange
    auto date = Date(2001, 1, 1, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto result = date.subtract(seconds(1));

    // Assert
    ASSERT_EQ(2000, result.getYear());
    ASSERT_EQ(12, result.getMonth());
    ASSERT_EQ(31, result.getDay());
    ASSERT_EQ(23, result.getHour());
    ASSERT_EQ(59, result.getMinute());
    ASSERT_EQ(59, result.getSecond());
}

TEST(Date, subtractDatePositive)
{
    // Arrange
    auto date = Date(2001, 1, 1, 0, 0, 10, DateKind::Unspecified);

    // Act
    auto result = date.subtract(Date(2001, 1, 1, 0, 0, 0, DateKind::Unspecified));

    // Assert
    ASSERT_EQ(10.f, result.asSeconds());
}

TEST(Date, subtractDateNegative)
{
    // Arrange
    auto date = Date(2001, 1, 1, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto result = date.subtract(Date(2001, 1, 1, 0, 0, 10, DateKind::Unspecified));

    // Assert
    ASSERT_EQ(-10.f, result.asSeconds());
}

TEST(Date, variousOperators)
{
    // Arrange
    auto date = Date(2000, 1, 1, 0, 0, 0, DateKind::Unspecified);
    auto dplus = date;
    auto dminus = date;

    // Act
    dplus += seconds(1);
    dminus -= seconds(1);

    // Assert
    ASSERT_EQ(Date(2000, 1, 1, 0, 0, 1, DateKind::Unspecified), dplus);
    ASSERT_EQ(Date(1999, 12, 31, 23, 59, 59, DateKind::Unspecified), dminus);
    ASSERT_EQ(Date(2000, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_NE(Date(2001, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_GT(Date(2001, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_GE(Date(2001, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_GE(Date(2000, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_LT(Date(1999, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_LE(Date(1999, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_LE(Date(2000, 1, 1, 0, 0, 0, DateKind::Unspecified), date);
    ASSERT_EQ(Date(2000, 1, 1, 0, 0, 1, DateKind::Unspecified), date + seconds(1));
    ASSERT_EQ(Date(1999, 12, 31, 23, 59, 59, DateKind::Unspecified), date - seconds(1));
    ASSERT_EQ(1.f, (date - Date(1999, 12, 31, 23, 59, 59, DateKind::Unspecified)).asSeconds());
    ASSERT_EQ(-1.f, (date - Date(2000, 1, 1, 0, 0, 1, DateKind::Unspecified)).asSeconds());
}

TEST(Date, toString)
{
    // Arrange
    auto date = Date(2000, 1, 1, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto string = date.toString();
    auto ansi = string.toAnsiString();

    // Assert
    ASSERT_FALSE(string.isEmpty());
}

TEST(Date, toStringFormat)
{
    // Arrange
    auto date = Date(2000, 1, 1, 0, 0, 0, DateKind::Unspecified);

    // Act
    auto string = date.toString("%F %T");

    // Assert
    ASSERT_EQ("2000-01-01 00:00:00", string);
}
