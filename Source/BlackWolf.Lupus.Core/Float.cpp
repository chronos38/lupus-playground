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
#include "Float.h"
#include <cstdio>
#include <cstring>
#include <exception>

#define BUFFER_SIZE 64
#ifdef _MSC_VER
#define snprintf _snprintf_s
#define sscanf sscanf_s
#endif

namespace sf {
	String Float::toString(float value)
	{
		char result[BUFFER_SIZE];
		memset(result, 0, BUFFER_SIZE);
		snprintf(result, BUFFER_SIZE, ("%f"), value);
		return result;
	}

	String Float::toString(double value)
	{
		char result[BUFFER_SIZE];
		memset(result, 0, BUFFER_SIZE);
        snprintf(result, BUFFER_SIZE, ("%lf"), value);
		return result;
	}
		
	String Float::toString(long double value)
	{
		char result[BUFFER_SIZE];
		memset(result, 0, BUFFER_SIZE);
        snprintf(result, BUFFER_SIZE, ("%Lf"), value);
		return result;
	}

	bool Float::tryParse(const String& value, float& result)
	{
        return (sscanf(value.toAnsiString().c_str(), ("%f"), &result) == 1);
	}

	bool Float::tryParse(const String& value, double& result)
	{
        return (sscanf(value.toAnsiString().c_str(), ("%lf"), &result) == 1);
	}

	bool Float::tryParse(const String& value, long double& result)
	{
        return (sscanf(value.toAnsiString().c_str(), ("%Lf"), &result) == 1);
	}

    float Float::parseFloat(const String& value)
    {
        float result = 0;

        if (!tryParse(value, result)) {
            throw std::invalid_argument("value");
        }

        return result;
    }
    
    double Float::parseDouble(const String& value)
    {
        double result = 0;

        if (!tryParse(value, result)) {
            throw std::invalid_argument("value");
        }

        return result;
    }
    
    long double Float::parseLongDouble(const String& value)
    {
        long double result = 0;

        if (!tryParse(value, result)) {
            throw std::invalid_argument("value");
        }

        return result;
    }
}
