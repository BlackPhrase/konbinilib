/*
 *	This file is part of konbinilib
 *	Copyright (C) 2018 BlackPhrase
 */

/// @file

#pragma once

#ifdef _WIN32
#	define KONBINI_PLATFORM KONBINI_PLATFORM_WINDOWS
#elif __linux__
#	define KONBINI_PLATFORM KONBINI_PLATFORM_LINUX
#elif __APPLE__
#	define KONBINI_PLATFORM KONBINI_PLATFORM_APPLE
#else
#	define KONBINI_PLATFORM KONBINI_PLATFORM_INVALID
#endif