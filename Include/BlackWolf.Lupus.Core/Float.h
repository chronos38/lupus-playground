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
#ifndef LUPUS_FLOAT_H
#define LUPUS_FLOAT_H
#ifdef _MSC_VER
#pragma once
#endif

#include "Configuration.h"
#include <SFML/System/String.hpp>

namespace sf {
	//! This class stores conversion methods for floating point numbers.
    class LUPUS_CORE_API Float
	{
	public:
		/**
		 * Converts a single precision floating point number to sf::String.
		 *
		 * \param[in] f Single precision floating point number.
		 * \returns String representation for floating point number.
		 */
		static String toString(float f);
		/// \sa Float::toString(float)
		static String toString(double d);
		/// \sa Float::toString(float)
        static String toString(long double r);
		/**
		 * Tries to convert a string to a single precision floating point number.
		 *
         * \param[in] value String to parse the value.
		 * \param[out] result Variable to store the result.
		 * \returns true if successful, otherwise false.
		 */
        static bool tryParse(const String& value, float& result);
		/// \sa Float::tryParse(const String&, float&)
        static bool tryParse(const String& value, double& result);
		/// \sa Float::tryParse(const String&, float&)
        static bool tryParse(const String& value, long double& result);
        /**
         * Parse a string and return the result as single precision floating point number.
         * If this method fails, it throws an std::invalid_argument exception.
         *
         * \param[in] value String to parse the value.
         * \returns Parsed value.
         */
        static float parseFloat(const String& value);
        /// \sa Float::parseFloat(const String&)
        static double parseDouble(const String& value);
        /// \sa Float::parseFloat(const String&)
        static long double parseLongDouble(const String& value);
	};
}

#endif
