#ifndef LUPUS_CONFIGURATION_HPP
#define LUPUS_CONFIGURATION_HPP

#ifdef NOEXCEPT
#undef NOEXCEPT
#endif

#ifdef _MSC_VER
#pragma once
#pragma warning(disable: 4290)
#define NOEXCEPT throw()

#ifdef LUPUS_CORE_EXPORT
#define LUPUS_CORE_API __declspec(dllexport)
#else
#define LUPUS_CORE_API __declspec(dllimport)
#endif

#else
#define NOEXCEPT noexcept

#ifdef LUPUS_CORE_EXPORT

#ifdef __CYGWIN__
#define LUPUS_CORE_API __attribute__ ((dllexport))
#else
#define LUPUS_CORE_API __attribute__ ((visibility ("default")))
#endif

#else

#ifdef __CYGWIN__
#define LUPUS_CORE_API __attribute__ ((dllimport))
#else
#define LUPUS_CORE_API __attribute__ ((visibility ("default")))
#endif

#endif
#endif

#endif
