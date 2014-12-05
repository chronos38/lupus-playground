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
#include "Integer.h"
#include <cstdio>
#include <cstring>
#include <exception>

#define BUFFER_SIZE 64

#ifdef _MSC_VER
#include <WinSock2.h>
#define snprintf _snprintf_s
#define sscanf sscanf_s
#else
#include <arpa/inet.h>
#if defined(__linux__)
#include <endian.h>
#elif defined(__FreeBSD__) || defined(__NetBSD__)
#include <sys/endian.h>
#elif defined(__OpenBSD__)
#define be16toh(x) betoh16(x)
#define be32toh(x) betoh32(x)
#define be64toh(x) betoh64(x)
#endif
#define ntohll be64toh
#define htonll htobe64
#endif

namespace sf {
    String toString(signed char value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%hhd"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%hhx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%hho"), value);
                break;
        }
        return result;
    }

    String toString(short value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%hd"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%hx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%ho"), value);
                break;
        }
        return result;
    }

    String toString(int value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%d"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%x"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%o"), value);
                break;
        }
        return result;
    }

    String toString(long value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%ld"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%lx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%lo"), value);
                break;
        }
        return result;
    }

    String toString(long long value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%lld"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%llx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%llo"), value);
                break;
        }
        return result;
    }

    String toString(unsigned char value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%hhu"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%hhx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%hho"), value);
                break;
        }
        return result;
    }

    String toString(unsigned short value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%hu"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%hx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%ho"), value);
                break;
        }
        return result;
    }

    String toString(unsigned int value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%u"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%x"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%o"), value);
                break;
        }
        return result;
    }

    String toString(unsigned long value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%lu"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%lx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%lo"), value);
                break;
        }
        return result;
    }

    String toString(unsigned long long value, IntegerBase base)
    {
        char result[BUFFER_SIZE];
        memset(result, 0, BUFFER_SIZE);

        switch (base) {
            case IntegerBase::Decimal:
                snprintf(result, BUFFER_SIZE, ("%llu"), value);
                break;
            case IntegerBase::Hexadecimal:
                snprintf(result, BUFFER_SIZE, ("%llx"), value);
                break;
            case IntegerBase::Octal:
                snprintf(result, BUFFER_SIZE, ("%llo"), value);
                break;
        }
        return result;
    }

    bool tryParse(const String& value, signed char& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hhd"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hhx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%hho"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, short& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hd"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%ho"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, int& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%d"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%x"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%o"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, long& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%ld"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%lx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%lo"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, long long& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%lld"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%llx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%llo"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, unsigned char& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hhu"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hhx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%hho"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, unsigned short& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hu"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%hx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%ho"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, unsigned int& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%u"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%x"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%o"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, unsigned long& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%lu"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%lx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%lo"), &result) == 1);
        }
        return false;
    }

    bool tryParse(const String& value, unsigned long long& result, IntegerBase base)
    {
        switch (base) {
            case IntegerBase::Decimal:
                return (sscanf(value.toAnsiString().c_str(), ("%llu"), &result) == 1);
            case IntegerBase::Hexadecimal:
                return (sscanf(value.toAnsiString().c_str(), ("%llx"), &result) == 1);
            case IntegerBase::Octal:
                return (sscanf(value.toAnsiString().c_str(), ("%llo"), &result) == 1);
        }
        return false;
    }

    signed char parseByte(const String& value, IntegerBase base)
    {
        signed char result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<signed char>::quiet_NaN();
        }

        return result;
    }

    short parseShort(const String& value, IntegerBase base)
    {
        short result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<short>::quiet_NaN();
        }

        return result;
    }

    int parseInt(const String& value, IntegerBase base)
    {
        int result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<int>::quiet_NaN();
        }

        return result;
    }

    long parseLong(const String& value, IntegerBase base)
    {
        long result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<long>::quiet_NaN();
        }

        return result;
    }

    long long parseLongLong(const String& value, IntegerBase base)
    {
        long long result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<long long>::quiet_NaN();
        }

        return result;
    }

    unsigned char parseUByte(const String& value, IntegerBase base)
    {
        unsigned char result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<unsigned char>::quiet_NaN();
        }

        return result;
    }

    unsigned short parseUShort(const String& value, IntegerBase base)
    {
        unsigned short result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<unsigned short>::quiet_NaN();
        }

        return result;
    }

    unsigned int parseUInt(const String& value, IntegerBase base)
    {
        unsigned int result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<unsigned int>::quiet_NaN();
        }

        return result;
    }

    unsigned long parseULong(const String& value, IntegerBase base)
    {
        unsigned long result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<unsigned long>::quiet_NaN();
        }

        return result;
    }

    unsigned long long parseULongLong(const String& value, IntegerBase base)
    {
        unsigned long long result = 0;

        if (!tryParse(value, result, base)) {
            return std::numeric_limits<unsigned long long>::quiet_NaN();
        }

        return result;
    }

    uint16_t toBigEndian(uint16_t host)
    {
        return htons(host);
    }

    uint32_t toBigEndian(uint32_t host)
    {
        return htonl(host);
    }

    uint64_t toBigEndian(uint64_t host)
    {
        return htonll(host);
    }

    uint16_t toLittleEndian(uint16_t network)
    {
        return ntohs(network);
    }

    uint32_t toLittleEndian(uint32_t network)
    {
        return ntohl(network);
    }

    uint64_t toLittleEndian(uint64_t network)
    {
        return ntohll(network);
    }
}
