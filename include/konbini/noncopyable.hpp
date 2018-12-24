/*
 *	This file is part of konbinilib
 *	Copyright (C) 2017-2018 BlackPhrase
 */

/// @file

#pragma once

namespace konbini
{

class noncopyable
{
public:
	noncopyable() = default;
	noncopyable(const noncopyable &) = delete;
	noncopyable &operator=(const noncopyable &) = delete;
};

}; // namespace konbini