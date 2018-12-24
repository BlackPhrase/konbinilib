/*
 *	This file is part of konbinilib
 *	Copyright (C) 2018 BlackPhrase
 */

/// @file

#pragma once

// Detect the platform
#include "platform.hpp"

// Check if the platform is even supported
#if KONBINI_PLATFORM == KONBINI_PLATFORM_INVALID
#	error "Invalid/unsupported platform type, sorry!"
#endif

// You're lucky!
#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
#	include "platform/platform_win.hpp"
#else if(KONBINI_PLATFORM == KONBINI_PLATFORM_LINUX) or if(KONBINI_PLATFORM == KONBINI_PLATFORM_APPLE)
#	include "platform/platform_unix.hpp"
#endif