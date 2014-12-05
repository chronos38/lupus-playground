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
#define snprintf _snprintf_s
#define sscanf sscanf_s
#endif

namespace sf {
    String Integer::toString(signed char value, IntegerBase base)
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

    String Integer::toString(short value, IntegerBase base)
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

    String Integer::toString(int value, IntegerBase base)
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

    String Integer::toString(long value, IntegerBase base)
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

    String Integer::toString(long long value, IntegerBase base)
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

    String Integer::toString(unsigned char value, IntegerBase base)
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

    String Integer::toString(unsigned short value, IntegerBase base)
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

    String Integer::toString(unsigned int value, IntegerBase base)
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

    String Integer::toString(unsigned long value, IntegerBase base)
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

    String Integer::toString(unsigned long long value, IntegerBase base)
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

    bool Integer::tryParse(const String& value, signed char& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, short& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, int& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, long& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, long long& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, unsigned char& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, unsigned short& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, unsigned int& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, unsigned long& result, IntegerBase base)
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

    bool Integer::tryParse(const String& value, unsigned long long& result, IntegerBase base)
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

    signed char Integer::parseByte(const String& value, IntegerBase base)
    {
        signed char result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    short Integer::parseShort(const String& value, IntegerBase base)
    {
        short result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    int Integer::parseInt(const String& value, IntegerBase base)
    {
        int result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    long Integer::parseLong(const String& value, IntegerBase base)
    {
        long result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    long long Integer::parseLongLong(const String& value, IntegerBase base)
    {
        long long result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    unsigned char Integer::parseUByte(const String& value, IntegerBase base)
    {
        unsigned char result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    unsigned short Integer::parseUShort(const String& value, IntegerBase base)
    {
        unsigned short result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    unsigned int Integer::parseUInt(const String& value, IntegerBase base)
    {
        unsigned int result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    unsigned long Integer::parseULong(const String& value, IntegerBase base)
    {
        unsigned long result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }

    unsigned long long Integer::parseULongLong(const String& value, IntegerBase base)
    {
        unsigned long long result = 0;

        if (!tryParse(value, result, base)) {
            throw std::invalid_argument("value");
        }

        return result;
    }
}
