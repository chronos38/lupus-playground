#include <BlackWolf.Lupus.Core/Float.h>
#include <gtest/gtest.h>

using namespace sf;

TEST(Float, toStringFloat)
{
    // Arrange
    const float f = 123.456f;

    // Act
    auto string = Float::toString(f);

    // Assert
    ASSERT_EQ("123.456001", string.toAnsiString());
}

TEST(Float, toStringDouble)
{
    // Arrange
    const double f = 123.456;

    // Act
    auto string = Float::toString(f);

    // Assert
    ASSERT_EQ("123.456000", string.toAnsiString());
}

TEST(Float, toStringLongDouble)
{
    // Arrange
    const long double f = 123.456;

    // Act
    auto string = Float::toString(f);

    // Assert
    ASSERT_EQ("123.456000", string.toAnsiString());
}

TEST(Float, tryParseFloat)
{
    // Arrange
    auto value = "123.456";
    float f = 0;

    // Act
    auto result = Float::tryParse(value, f);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123.456f, f);
}

TEST(Float, tryParseDouble)
{
    // Arrange
    auto value = "123.456";
    double f = 0;

    // Act
    auto result = Float::tryParse(value, f);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123.456, f);
}

TEST(Float, tryParseLongDouble)
{
    // Arrange
    auto value = "123.456";
    long double f = 0;

    // Act
    auto result = Float::tryParse(value, f);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123.456, f);
}

TEST(Float, tryParseError)
{
    float i = 0;
    ASSERT_FALSE(Float::tryParse("zzzzzz", i));
}
