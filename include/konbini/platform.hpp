/// @file

#pragma once

namespace konbini
{

#define KONBINI_PLATFORM_INVALID -1
#define KONBINI_PLATFORM_WINDOWS 1
#define KONBINI_PLATFORM_LINUX 2
#define KONBINI_PLATFORM_APPLE 3

#define KONBINI_PLATFORM KONBINI_PLATFORM_INVALID

#ifdef _WIN32
#	define KONBINI_PLATFORM KONBINI_PLATFORM_WINDOWS
#elif __linux__
#	define KONBINI_PLATFORM KONBINI_PLATFORM_LINUX
#elif __APPLE__
#	define KONBINI_PLATFORM KONBINI_PLATFORM_APPLE
#else
#	error "Unsupported platform!"
#endif

enum class PlatformType : int
{
	Invalid = -1,
	
	Windows,
	Linux,
	Apple
};

#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
	constexpr PlatformType Platform{PlatformType::Windows};
#elif KONBINI_PLATFORM == KONBINI_PLATFORM_LINUX
	constexpr PlatformType Platform{PlatformType::Linux};
#elif KONBINI_PLATFORM == KONBINI_PLATFORM_APPLE
	constexpr PlatformType Platform{PlatformType::Apple};
#else
	constexpr PlatformType Platform{PlatformType::Invalid};
#endif

}; // namespace konbini