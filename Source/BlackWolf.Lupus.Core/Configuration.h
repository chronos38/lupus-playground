#ifndef LUPUS_CONFIGURATION_H
#define LUPUS_CONFIGURATION_H

#ifdef _MSC_VER
#pragma once
#pragma warning(disable: 4290)

#ifdef LUPUS_CORE_EXPORT
#define LUPUS_CORE_API __declspec(dllexport)
#else
#define LUPUS_CORE_API __declspec(dllimport)
#endif

#else

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
