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

TEST(Numeric, tryParseDoubleError)
{
    double i = 0;
    ASSERT_FALSE(tryParse("zzzzzz", i));
}

TEST(Numeric, tryParseLongDoubleError)
{
    long double i = 0;
    ASSERT_FALSE(tryParse("zzzzzz", i));
}

TEST(Numeric, parseFloat)
{
    ASSERT_EQ(1.2f, parseFloat("1.2"));
}

TEST(Numeric, parseFloatError)
{
    ASSERT_TRUE(isnan(parseFloat("zzzzzz")));
    ASSERT_TRUE(isnan(parseDouble("zzzzzz")));
    ASSERT_TRUE(isnan(parseLongDouble("zzzzzz")));
}

TEST(Numeric, parseDouble)
{
    ASSERT_EQ(1.2, parseDouble("1.2"));
}

TEST(Numeric, parseLongDouble)
{
    ASSERT_EQ(1.2, parseLongDouble("1.2"));
}

TEST(Numeric, toStringOctal)
{
    // Arrange
    int i = 123;

    // Act
    auto string = toString(i, Octal);
    toString((signed char)i, Octal);
    toString((short)i, Octal);
    toString((long)i, Octal);
    toString((long long)i, Octal);
    toString((unsigned char)i, Octal);
    toString((unsigned short)i, Octal);
    toString((unsigned int)i, Octal);
    toString((unsigned long)i, Octal);
    toString((unsigned long long)i, Octal);

    // Assert
    ASSERT_EQ("173", string.toAnsiString());
}

TEST(Numeric, toStringDecimal)
{
    // Arrange
    int i = 123;

    // Act
    auto string = toString(i, Decimal);
    toString((signed char)i, Decimal);
    toString((short)i, Decimal);
    toString((long)i, Decimal);
    toString((long long)i, Decimal);
    toString((unsigned char)i, Decimal);
    toString((unsigned short)i, Decimal);
    toString((unsigned int)i, Decimal);
    toString((unsigned long)i, Decimal);
    toString((unsigned long long)i, Decimal);

    // Assert
    ASSERT_EQ("123", string.toAnsiString());
}

TEST(Numeric, toStringHexadecimal)
{
    // Arrange
    int i = 123;

    // Act
    auto string = toString(i, Hexadecimal);
    toString((signed char)i, Hexadecimal);
    toString((short)i, Hexadecimal);
    toString((long)i, Hexadecimal);
    toString((long long)i, Hexadecimal);
    toString((unsigned char)i, Hexadecimal);
    toString((unsigned short)i, Hexadecimal);
    toString((unsigned int)i, Hexadecimal);
    toString((unsigned long)i, Hexadecimal);
    toString((unsigned long long)i, Hexadecimal);

    // Assert
    ASSERT_EQ("7b", string.toAnsiString());
}

TEST(Numeric, tryParseOctal)
{
    // Arrange
    signed char sc;
    short s;
    long l;
    long long ll;
    unsigned char uc;
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;

    int i = 0;
    String value = "173";

    // Act
    auto result = tryParse(value, i, Octal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123, i);
    ASSERT_TRUE(tryParse(value, sc, Octal));
    ASSERT_TRUE(tryParse(value, s, Octal));
    ASSERT_TRUE(tryParse(value, l, Octal));
    ASSERT_TRUE(tryParse(value, ll, Octal));
    ASSERT_TRUE(tryParse(value, uc, Octal));
    ASSERT_TRUE(tryParse(value, us, Octal));
    ASSERT_TRUE(tryParse(value, ui, Octal));
    ASSERT_TRUE(tryParse(value, ul, Octal));
    ASSERT_TRUE(tryParse(value, ull, Octal));
}

TEST(Numeric, tryParseDecimal)
{
    // Arrange
    signed char sc;
    short s;
    long l;
    long long ll;
    unsigned char uc;
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;

    int i = 0;
    String value = "123";

    // Act
    auto result = tryParse(value, i, Decimal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123, i);
    ASSERT_TRUE(tryParse(value, sc, Decimal));
    ASSERT_TRUE(tryParse(value, s, Decimal));
    ASSERT_TRUE(tryParse(value, l, Decimal));
    ASSERT_TRUE(tryParse(value, ll, Decimal));
    ASSERT_TRUE(tryParse(value, uc, Decimal));
    ASSERT_TRUE(tryParse(value, us, Decimal));
    ASSERT_TRUE(tryParse(value, ui, Decimal));
    ASSERT_TRUE(tryParse(value, ul, Decimal));
    ASSERT_TRUE(tryParse(value, ull, Decimal));
}

TEST(Numeric, tryParseHexadecimal)
{
    // Arrange
    signed char sc;
    short s;
    long l;
    long long ll;
    unsigned char uc;
    unsigned short us;
    unsigned int ui;
    unsigned long ul;
    unsigned long long ull;

    int i = 0;
    String value = "7b";

    // Act
    auto result = tryParse(value, i, Hexadecimal);

    // Assert
    ASSERT_TRUE(result);
    ASSERT_EQ(123, i);
    ASSERT_TRUE(tryParse(value, sc, Hexadecimal));
    ASSERT_TRUE(tryParse(value, s, Hexadecimal));
    ASSERT_TRUE(tryParse(value, l, Hexadecimal));
    ASSERT_TRUE(tryParse(value, ll, Hexadecimal));
    ASSERT_TRUE(tryParse(value, uc, Hexadecimal));
    ASSERT_TRUE(tryParse(value, us, Hexadecimal));
    ASSERT_TRUE(tryParse(value, ui, Hexadecimal));
    ASSERT_TRUE(tryParse(value, ul, Hexadecimal));
    ASSERT_TRUE(tryParse(value, ull, Hexadecimal));
}

TEST(Numeric, tryParseIntError)
{
    int i = 0;
    ASSERT_FALSE(tryParse("zzzzzz", i));
}

TEST(Numeric, parseVarious)
{
    ASSERT_EQ(123, parseByte("123"));
    ASSERT_EQ(123, parseShort("123"));
    ASSERT_EQ(123, parseInt("123"));
    ASSERT_EQ(123, parseLong("123"));
    ASSERT_EQ(123, parseLongLong("123"));
    ASSERT_EQ(123, parseUnsignedByte("123"));
    ASSERT_EQ(123, parseUnsignedShort("123"));
    ASSERT_EQ(123, parseUnsignedInt("123"));
    ASSERT_EQ(123, parseUnsignedLong("123"));
    ASSERT_EQ(123, parseUnsignedLongLong("123"));
    EXPECT_THROW({
        parseByte("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseShort("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseInt("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseLong("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseLongLong("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseUnsignedByte("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseUnsignedShort("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseUnsignedInt("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseUnsignedLong("zzzzzz");
    }, std::invalid_argument);
    EXPECT_THROW({
        parseUnsignedLongLong("zzzzzz");
    }, std::invalid_argument);
}

TEST(Numeric, toBigEndian16)
{
    // Arrange
    Uint16 le = 0x1234;

    // Act
    auto be = toBigEndian(le);
    auto ple = (char*)&le;
    auto pbe = (char*)&be;

    // Assert
    for (int i = 0; i < sizeof(le); i++) {
        ASSERT_EQ((int)*(ple + i), (int)*(pbe + (sizeof(le) - i - 1)));
    }
}

TEST(Numeric, toBigEndian32)
{
    // Arrange
    Uint32 le = 0x12345678;

    // Act
    auto be = toBigEndian(le);
    auto ple = (char*)&le;
    auto pbe = (char*)&be;

    // Assert
    for (int i = 0; i < sizeof(le); i++) {
        ASSERT_EQ((int)*(ple + i), (int)*(pbe + (sizeof(le) - i - 1)));
    }
}

TEST(Numeric, toBigEndian64)
{
    // Arrange
    Uint64 le = 0x123456789abcdef0;

    // Act
    auto be = toBigEndian(le);
    auto ple = (char*)&le;
    auto pbe = (char*)&be;

    // Assert
    for (int i = 0; i < sizeof(le); i++) {
        ASSERT_EQ((int)*(ple + i), (int)*(pbe + (sizeof(le) - i - 1)));
    }
}

TEST(Numeric, toLittleEndian16)
{
    // Arrange
    auto be = toBigEndian((Uint16)0x1234);

    // Act
    auto le = toLittleEndian(be);
    auto ple = (char*)&le;
    auto pbe = (char*)&be;

    // Assert
    for (int i = 0; i < sizeof(le); i++) {
        ASSERT_EQ((int)*(ple + i), (int)*(pbe + (sizeof(le) - i - 1)));
    }
}

TEST(Numeric, toLittleEndian32)
{
    // Arrange
    auto be = toBigEndian((Uint32)0x12345678);

    // Act
    auto le = toLittleEndian(be);
    auto ple = (char*)&le;
    auto pbe = (char*)&be;

    // Assert
    for (int i = 0; i < sizeof(le); i++) {
        ASSERT_EQ((int)*(ple + i), (int)*(pbe + (sizeof(le) - i - 1)));
    }
}

TEST(Numeric, toLittleEndian64)
{
    // Arrange
    auto be = toBigEndian((Uint64)0x123456789abcdef0);

    // Act
    auto le = toLittleEndian(be);
    auto ple = (char*)&le;
    auto pbe = (char*)&be;

    // Assert
    for (int i = 0; i < sizeof(le); i++) {
        ASSERT_EQ((int)*(ple + i), (int)*(pbe + (sizeof(le) - i - 1)));
    }
}
