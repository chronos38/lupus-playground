#include "BlackWolf.Lupus.Core/Integer.h"
#include "gtest/gtest.h"

using namespace sf;

TEST(Integer, toStringOctal)
{
    // Arrange
    int i = 123456;

    // Act
    auto string = Integer::toString(i, IntegerBase::Octal);

    // Assert
    ASSERT_EQ("361100", string.toAnsiString());
}

TEST(Integer, toStringDecimal)
{
    // Arrange
    int i = 123456;

    // Act
    auto string = Integer::toString(i, IntegerBase::Decimal);

    // Assert
    ASSERT_EQ("123456", string.toAnsiString());
}

TEST(Integer, toStringHexadecimal)
{
    // Arrange
    int i = 123456;

    // Act
    auto string = Integer::toString(i, IntegerBase::Hexadecimal);

    // Assert
    ASSERT_EQ("1e240", string.toAnsiString());
}

TEST(Integer, tryParseOctal)
{
    // Arrange
    int i = 0;
    String value = "361100";

    // Act
    auto result = Integer::tryParse(value, i, IntegerBase::Octal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123456, i);
}

TEST(Integer, tryParseDecimal)
{
    // Arrange
    int i = 0;
    String value = "123456";

    // Act
    auto result = Integer::tryParse(value, i, IntegerBase::Decimal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123456, i);
}

TEST(Integer, tryParseHexadecimal)
{
    // Arrange
    int i = 0;
    String value = "1e240";

    // Act
    auto result = Integer::tryParse(value, i, IntegerBase::Hexadecimal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123456, i);
}

TEST(Integer, tryParseError)
{
    int i = 0;
    ASSERT_FALSE(Integer::tryParse("zzzzzz", i));
}
