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
#ifndef LUPUS_NUMERIC_H
#define LUPUS_NUMERIC_H
#ifdef _MSC_VER
#pragma once
#endif

#include "Configuration.h"
#include <SFML/System/String.hpp>

namespace sf {
	//! Base for integer conversion.
	enum IntegerBase {
		Octal, //!< Use octal as base.
		Decimal, //!< Use decimal as base.
		Hexadecimal //!< Use hexadecimal as base.
    };
    /*!
     * Converts a single precision floating point number to sf::String.
     *
     * \param[in] f Single precision floating point number.
     * \returns String representation for floating point number.
     */
    LUPUS_CORE_API String toString(float f);
    /// \sa Float::toString(float)
    LUPUS_CORE_API String toString(double d);
    /// \sa Float::toString(float)
    LUPUS_CORE_API String toString(long double r);
    /*!
     * Tries to convert a string to a single precision floating point number.
     *
     * \param[in] value String to parse the value.
     * \param[out] result Variable to store the result.
     * \returns true if successful, otherwise false.
     */
    LUPUS_CORE_API bool tryParse(const String& value, float& result);
    /// \sa Float::tryParse(const String&, float&)
    LUPUS_CORE_API bool tryParse(const String& value, double& result);
    /// \sa Float::tryParse(const String&, float&)
    LUPUS_CORE_API bool tryParse(const String& value, long double& result);
    /*!
     * Parse a string and return the result as single precision floating point number.
     * If this method fails, it returns NaN.
     *
     * \param[in] value String to parse the value.
     * \returns Parsed value.
     */
    LUPUS_CORE_API float parseFloat(const String& value);
    /// \sa Float::parseFloat(const String&)
    LUPUS_CORE_API double parseDouble(const String& value);
    /// \sa Float::parseFloat(const String&)
    LUPUS_CORE_API long double parseLongDouble(const String& value);
	//! \sa Integer::toString(int, IntegerBase)
	LUPUS_CORE_API String toString(signed char value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(short value, IntegerBase base = Decimal);
	/*!
	 * Converts a integer to its string representation.
	 *
	 * \param[in] value Integer to convert.
	 * \param[in] base Base for conversion (8, 10, 16).
	 * \returns String representation for given integer.
	 */
    LUPUS_CORE_API String toString(int value, IntegerBase base = Decimal) ;
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(long value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(long long value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned char value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned short value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned int value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned long value, IntegerBase base = Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned long long value, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, signed char& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, short& result, IntegerBase base = Decimal);
	/*!
	 * Tries to convert a string to its integer value.
	 *
	 * \param[in] value String with integer as content.
	 * \param[out] result Variable to store the result.
	 * \param[in] base Base for conversion (8, 10, 16)
	 * \returns true if successful, otherwise false.
	 */
    LUPUS_CORE_API bool tryParse(const String& value, int& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, long& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, long long& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned char& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned short& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned int& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned long& result, IntegerBase base = Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned long long& result, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API signed char parseByte(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API short parseShort(const String& value, IntegerBase base = Decimal);
    /*!
     * Parse given string value and return it as an integer. If the string is not
     * a valid integer, this method returns NaN.
     *
     * \param[in] value String value to parse.
     * \param[in] base Base for conversion.
     * \returns Parsed result as integer.
     */
    LUPUS_CORE_API int parseInt(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API long parseLong(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API long long parseLongLong(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned char parseUnsignedByte(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned short parseUnsignedShort(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned int parseUnsignedInt(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned long parseUnsignedLong(const String& value, IntegerBase base = Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned long long parseUnsignedLongLong(const String& value, IntegerBase base = Decimal);
    /*!
     * Converts 16-Bit integer to big-endian byte order.
     *
     * \returns Integer with big-endian byte order.
     */
    LUPUS_CORE_API Uint16 toBigEndian(Uint16 host);
    /*!
     * Converts 32-Bit integer to big-endian byte order.
     *
     * \returns Integer with big-endian byte order.
     */
    LUPUS_CORE_API Uint32 toBigEndian(Uint32 host);
    /*!
     * Converts 64-Bit integer to big-endian byte order.
     *
     * \returns Integer with big-endian byte order.
     */
    LUPUS_CORE_API Uint64 toBigEndian(Uint64 host);
    /*!
     * Converts 16-Bit integer to little-endian byte order.
     *
     * \returns Integer with little-endian byte order.
     */
    LUPUS_CORE_API Uint16 toLittleEndian(Uint16 network);
    /*!
     * Converts 32-Bit integer to little-endian byte order.
     *
     * \returns Integer with little-endian byte order.
     */
    LUPUS_CORE_API Uint32 toLittleEndian(Uint32 network);
    /*!
     * Converts 64-Bit integer to little-endian byte order.
     *
     * \returns Integer with little-endian byte order.
     */
    LUPUS_CORE_API Uint64 toLittleEndian(Uint64 network);
}

#endif
