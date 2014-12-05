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
#include <cstdint>

namespace sf {
	//! Base for integer conversion.
	enum class IntegerBase {
		Octal, //!< Use octal as base.
		Decimal, //!< Use decimal as base.
		Hexadecimal //!< Use hexadecimal as base.
	};

	//! \sa Integer::toString(int, IntegerBase)
	LUPUS_CORE_API String toString(signed char value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(short value, IntegerBase base = IntegerBase::Decimal);
	/*!
	 * Converts a integer to its string representation.
	 *
	 * \param[in] value Integer to convert.
	 * \param[in] base Base for conversion (8, 10, 16).
	 * \returns String representation for given integer.
	 */
    LUPUS_CORE_API String toString(int value, IntegerBase base = IntegerBase::Decimal) ;
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(long value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(long long value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned char value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned short value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned int value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned long value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::toString(int, IntegerBase)
    LUPUS_CORE_API String toString(unsigned long long value, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, signed char& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, short& result, IntegerBase base = IntegerBase::Decimal);
	/*!
	 * Tries to convert a string to its integer value.
	 *
	 * \param[in] value String with integer as content.
	 * \param[out] result Variable to store the result.
	 * \param[in] base Base for conversion (8, 10, 16)
	 * \returns true if successful, otherwise false.
	 */
    LUPUS_CORE_API bool tryParse(const String& value, int& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, long& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, long long& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned char& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned short& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned int& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned long& result, IntegerBase base = IntegerBase::Decimal);
	//! \sa Integer::tryParse(const String&, int, IntegerBase)
    LUPUS_CORE_API bool tryParse(const String& value, unsigned long long& result, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API signed char parseByte(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API short parseShort(const String& value, IntegerBase base = IntegerBase::Decimal);
    /*!
     * Parse given string value and return it as integer. If the string is not
     * a valid integer, this method returns NaN.
     *
     * \param[in] value String value to parse.
     * \param[in] base Base for conversion.
     * \returns Parsed result as integer.
     */
    LUPUS_CORE_API int parseInt(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API long parseLong(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API long long parseLongLong(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned char parseUByte(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned short parseUShort(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned int parseUInt(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned long parseULong(const String& value, IntegerBase base = IntegerBase::Decimal);
    //! \sa Integer::parseInt(const String&, IntegerBase)
    LUPUS_CORE_API unsigned long long parseULongLong(const String& value, IntegerBase base = IntegerBase::Decimal);
    /*!
     * Converts 16-Bit integer to big-endian byte order.
     *
     * \returns Integer with big-endian byte order.
     */
    LUPUS_CORE_API uint16_t toBigEndian(uint16_t host);
    /*!
     * Converts 32-Bit integer to big-endian byte order.
     *
     * \returns Integer with big-endian byte order.
     */
    LUPUS_CORE_API uint32_t toBigEndian(uint32_t host);
    /*!
     * Converts 64-Bit integer to big-endian byte order.
     *
     * \returns Integer with big-endian byte order.
     */
    LUPUS_CORE_API uint64_t toBigEndian(uint64_t host);
    /*!
     * Converts 16-Bit integer to little-endian byte order.
     *
     * \returns Integer with little-endian byte order.
     */
    LUPUS_CORE_API uint16_t toLittleEndian(uint16_t network);
    /*!
     * Converts 32-Bit integer to little-endian byte order.
     *
     * \returns Integer with little-endian byte order.
     */
    LUPUS_CORE_API uint32_t toLittleEndian(uint32_t network);
    /*!
     * Converts 64-Bit integer to little-endian byte order.
     *
     * \returns Integer with little-endian byte order.
     */
    LUPUS_CORE_API uint64_t toLittleEndian(uint64_t network);
}
