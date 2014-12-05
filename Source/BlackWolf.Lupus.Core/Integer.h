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
#pragma once

#include "Configuration.h"
#include <SFML/System/String.hpp>

namespace sf {
	//! Base for integer conversion.
	enum class IntegerBase {
		Octal, //!< Use octal as base.
		Decimal, //!< Use decimal as base.
		Hexadecimal //!< Use hexadecimal as base.
	};

    //! This class stores conversion methods for integer numbers.
    class LUPUS_CORE_API Integer
	{
	public:
		//! \sa Integer::toString(int, IntegerBase)
		static String toString(signed char value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(short value, IntegerBase base = IntegerBase::Decimal);
		/*!
		 * Converts a integer to its string representation.
		 *
		 * \param[in] value Integer to convert.
		 * \param[in] base Base for conversion (8, 10, 16).
		 * \returns String representation for given integer.
		 */
        static String toString(int value, IntegerBase base = IntegerBase::Decimal) ;
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(long value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(long long value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(unsigned char value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(unsigned short value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(unsigned int value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(unsigned long value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::toString(int, IntegerBase)
        static String toString(unsigned long long value, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, signed char& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, short& result, IntegerBase base = IntegerBase::Decimal);
		/*!
		 * Tries to convert a string to its integer value.
		 *
		 * \param[in] value String with integer as content.
		 * \param[out] result Variable to store the result.
		 * \param[in] base Base for conversion (8, 10, 16)
		 * \returns true if successful, otherwise false.
		 */
        static bool tryParse(const String& value, int& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, long& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, long long& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, unsigned char& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, unsigned short& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, unsigned int& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, unsigned long& result, IntegerBase base = IntegerBase::Decimal);
		//! \sa Integer::tryParse(const String&, int, IntegerBase)
        static bool tryParse(const String& value, unsigned long long& result, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static signed char parseByte(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static short parseShort(const String& value, IntegerBase base = IntegerBase::Decimal);
        /*!
         * Parse given string value and return it as integer. If the string is not
         * a valid integer, this method throws an std::invalid_argument exception.
         *
         * \param[in] value String value to parse.
         * \param[in] base Base for conversion.
         * \returns Parsed result as integer.
         */
        static int parseInt(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static long parseLong(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static long long parseLongLong(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static unsigned char parseUByte(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static unsigned short parseUShort(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static unsigned int parseUInt(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static unsigned long parseULong(const String& value, IntegerBase base = IntegerBase::Decimal);
        //! \sa Integer::parseInt(const String&, IntegerBase)
        static unsigned long long parseULongLong(const String& value, IntegerBase base = IntegerBase::Decimal);
	};
}
