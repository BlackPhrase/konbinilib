/*
 *	This file is part of konbinilib
 *	Copyright (C) 2018 BlackPhrase
 */

/// @file

#pragma once

namespace konbini
{

#define KONBINI_PLATFORM PlatformType::Invalid

#ifdef _WIN32
#	define KONBINI_PLATFORM PlatformType::Windows
#elif __linux__
#	define KONBINI_PLATFORM PlatformType::Linux
#elif __APPLE__
#	define KONBINI_PLATFORM PlatformType::Apple
#else
#	error "Unsupported platform!"
#endif

#if KONBINI_PLATFORM == PlatformType::Windows
	static constexpr PlatformType Platform{PlatformType::Windows};
#elif KONBINI_PLATFORM == PlatformType::Linux
	static constexpr PlatformType Platform{PlatformType::Linux};
#elif KONBINI_PLATFORM == PlatformType::Apple
	static constexpr PlatformType Platform{PlatformType::Apple};
#else
	static constexpr PlatformType Platform{PlatformType::Invalid};
#endif

}; // namespace konbini