#include "BlackWolf.Lupus.Core/Numeric.h"
#include "gtest/gtest.h"

using namespace sf;

TEST(Numeric, toStringFloat)
{
    // Arrange
    const float f = 123.456f;

    // Act
    auto string = toString(f);

    // Assert
    ASSERT_EQ("123.456001", string.toAnsiString());
}

TEST(Numeric, toStringDouble)
{
    // Arrange
    const double f = 123.456;

    // Act
    auto string = toString(f);

    // Assert
    ASSERT_EQ("123.456000", string.toAnsiString());
}

TEST(Numeric, toStringLongDouble)
{
    // Arrange
    const long double f = 123.456;

    // Act
    auto string = toString(f);

    // Assert
    ASSERT_EQ("123.456000", string.toAnsiString());
}

TEST(Numeric, tryParseFloat)
{
    // Arrange
    auto value = "123.456";
    float f = 0;

    // Act
    auto result = tryParse(value, f);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123.456f, f);
}

TEST(Numeric, tryParseDouble)
{
    // Arrange
    auto value = "123.456";
    double f = 0;

    // Act
    auto result = tryParse(value, f);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123.456, f);
}

TEST(Numeric, tryParseLongDouble)
{
    // Arrange
    auto value = "123.456";
    long double f = 0;

    // Act
    auto result = tryParse(value, f);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123.456, f);
}

TEST(Numeric, tryParseFloatError)
{
    float i = 0;
    ASSERT_FALSE(tryParse("zzzzzz", i));
}

TEST(Numeric, toStringOctal)
{
    // Arrange
    int i = 123456;

    // Act
    auto string = toString(i, IntegerBase::Octal);

    // Assert
    ASSERT_EQ("361100", string.toAnsiString());
}

TEST(Numeric, toStringDecimal)
{
    // Arrange
    int i = 123456;

    // Act
    auto string = toString(i, IntegerBase::Decimal);

    // Assert
    ASSERT_EQ("123456", string.toAnsiString());
}

TEST(Numeric, toStringHexadecimal)
{
    // Arrange
    int i = 123456;

    // Act
    auto string = toString(i, IntegerBase::Hexadecimal);

    // Assert
    ASSERT_EQ("1e240", string.toAnsiString());
}

TEST(Numeric, tryParseOctal)
{
    // Arrange
    int i = 0;
    String value = "361100";

    // Act
    auto result = tryParse(value, i, IntegerBase::Octal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123456, i);
}

TEST(Numeric, tryParseDecimal)
{
    // Arrange
    int i = 0;
    String value = "123456";

    // Act
    auto result = tryParse(value, i, IntegerBase::Decimal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123456, i);
}

TEST(Numeric, tryParseHexadecimal)
{
    // Arrange
    int i = 0;
    String value = "1e240";

    // Act
    auto result = tryParse(value, i, IntegerBase::Hexadecimal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123456, i);
}

TEST(Numeric, tryParseIntError)
{
    int i = 0;
    ASSERT_FALSE(tryParse("zzzzzz", i));
}
