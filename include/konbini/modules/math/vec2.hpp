/*
 *	This file is part of konbinilib
 *	Copyright (C) 2017-2019 BlackPhrase
 */

/// @file
/// @brief 2d vector class

#pragma once

#include <cmath>

namespace konbini::math
{

//template<typename T>
class vec2 final
{
public:
	// Constructors
	
	///
	vec2() = default;
	
	///
	vec2(float value) : vec2(value, value){}
	
	///
	vec2(float x, float y) : x(x), y(y){}
	
	// Methods
	
	inline float length() const {return sqrt(x*x + y*y);}
	
	void normalize()
	{
		if(length() <= 0.0f)
			return;
		
		x /= length();
		y /= length();
	};
	
	vec2 normalized()
	{
		vec2 vNormalized{};
		
		vNormalized.x = x / length();
		vNormalized.y = y / length();
		
		//if(this->length() > 0.0f)
			//vec2 vNormalized = this / length();
		
		return vNormalized;
	};
	
	// Operator overloading
	
	///
	bool operator==(const vec2 &other)
	{
		if(x == other.x && y == other.y)
			return true;
		
		return false;
	};
	
	///
	inline bool operator!=(const vec2 &other){return !(*this == other);}
	
	///
	inline vec2 operator+(const vec2 &other){return vec2(x + other.x, y + other.y);}
	
	///
	inline vec2 operator-(const vec2 &other){return vec2(x - other.x, y - other.y);}
	
	///
	inline vec2 operator*(const vec2 &other){return vec2(x * other.x, y * other.y);}
	
	///
	inline vec2 operator/(const vec2 &other){return vec2(x / other.x, y / other.y);}
	
	///
	vec2 &operator+=(const vec2 &other)
	{
		x += other.x;
		y += other.y;
		return *this;
	};
	
	///
	vec2 &operator-=(const vec2 &other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	};
	
	///
	vec2 &operator*=(const vec2 &other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	};
	
	///
	vec2 &operator/=(const vec2 &other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	};
	
	///
	float x{0.0f}, y{0.0f};
};

}; // namespace konbini::math