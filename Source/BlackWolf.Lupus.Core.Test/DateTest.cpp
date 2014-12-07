#include <BlackWolf.Lupus.Core/Date.h>
#include <gtest/gtest.h>

using namespace sf;

TEST(Date, ConstructorTicks)
{
    EXPECT_NO_THROW({
        // Arrange
        auto time = std::time(NULL);
        auto date = Date(time);

        // Act
        auto tm = localtime(&time);

        // Assert
        ASSERT_EQ(date.getYear(), tm->tm_year + 1900);
        ASSERT_EQ(date.getMonth(), tm->tm_mon + 1);
        ASSERT_EQ(date.getDay(), tm->tm_mday);
        ASSERT_EQ(date.getHour(), tm->tm_hour);
        ASSERT_EQ(date.getMinute(), tm->tm_min);
        ASSERT_EQ(date.getSecond(), tm->tm_sec);

        ASSERT_EQ(date.getDayOfWeek(), tm->tm_wday);
        ASSERT_EQ(date.getDayOfYear(), tm->tm_yday);
    });
}

TEST(Date, ConstructorIntegerUnspecified)
{
    EXPECT_NO_THROW({
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
    });
}

TEST(Date, ConstructorIntegerLocal)
{
    EXPECT_NO_THROW({
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
    });
}

TEST(Date, ConstructorIntegerUtc)
{
    EXPECT_NO_THROW({
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
    });
}

TEST(Date, ConstructorInvalidZero)
{
    EXPECT_THROW({
        auto date = Date(0, 0, 0, 0, 0, 0, DateKind::Unspecified);
    }, std::range_error);
}

TEST(Date, ConstructorInvalidMax)
{
    EXPECT_THROW({
        auto date = Date(std::numeric_limits<Int32>::max(), 0, 0, 0, 0, 0, DateKind::Unspecified);
    }, std::range_error);
}

TEST(Date, ConstructorInvalidMin)
{
    EXPECT_THROW({
        auto date = Date(std::numeric_limits<Int32>::min(), 0, 0, 0, 0, 0, DateKind::Unspecified);
    }, std::range_error);
}

TEST(Date, ConstructorVarious)
{
    EXPECT_NO_THROW({
        Date(2000, 1, 1);
        Date(2000, 1, 1, DateKind::Unspecified);
        Date(2000, 1, 1, 1, 1, 1);
    });
}
