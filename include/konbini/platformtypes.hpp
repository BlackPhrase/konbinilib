/*
 *	This file is part of konbinilib
 *	Copyright (C) 2018 BlackPhrase
 */

/// @file

#pragma once

#define KONBINI_PLATFORM_INVALID -1
	
#define KONBINI_PLATFORM_WINDOWS 0
#define KONBINI_PLATFORM_LINUX 1
#define KONBINI_PLATFORM_APPLE 2

// Detect the platform
#include "platform/platformdetector.hpp"

// Check if the platform is even supported
#if KONBINI_PLATFORM == KONBINI_PLATFORM_INVALID
#	error "Invalid/unsupported platform type, sorry!"
#endif

enum class PlatformType : int
{
	Invalid = -1,
	
	Windows,
	Linux,
	Apple
};

// You're lucky!
#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
#	include "platform/platform_win.hpp"
#elif (KONBINI_PLATFORM == KONBINI_PLATFORM_LINUX) or (KONBINI_PLATFORM == KONBINI_PLATFORM_APPLE)
#	include "platform/platform_unix.hpp"

#	if (KONBINI_PLATFORM == KONBINI_PLATFORM_LINUX)
#		include "platform/platform_linux.hpp"
#	elif (KONBINI_PLATFORM == KONBINI_PLATFORM_APPLE)
#		include "platform/platform_apple.hpp"
#	endif
#else
	constexpr PlatformType Platform{PlatformType::Invalid};
#endif