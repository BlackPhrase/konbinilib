/*
 *	This file is part of konbinilib
 *	Copyright (C) 2018 BlackPhrase
 */

/// @file
/// @brief Windows platform types

#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace konbini
{

constexpr PlatformType Platform{PlatformType::Windows};

using tLibHandle = HMODULE;

}; // namespace konbini