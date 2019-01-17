/*
 *	This file is part of konbinilib
 *	Copyright (C) 2017-2019 BlackPhrase
 */

/// @file
/// @brief 3d vector class

#pragma once

#include <cmath>

namespace konbini::math
{

//template<typename T>
class vec3 final
{
public:
	// Constructors
	
	///
	vec3() : vec3(0.0f){}
	
	///
	vec3(float value) : vec3(value, value, value){}
	
	///
	vec3(float x, float y, float z) : x(x), y(y), z(z){}
	
	// Methods
	
	float length() const
	{
		return sqrt(x*x + y*y + z*z);
	};
	
	// Operator overloading
	
	///
	bool operator==(const vec3 &other)
	{
		if(x == other.x && y == other.y && z == other.z)
			return true;
		
		return false;
	};
	
	///
	bool operator!=(const vec3 &other){return !(*this == other);}
	
	///
	vec3 operator+(const vec3 &other){return vec3(x + other.x, y + other.y, z + other.z);}
	
	///
	vec3 operator-(const vec3 &other){return vec3(x - other.x, y - other.y, z - other.z);}
	
	///
	vec3 operator*(const vec3 &other){return vec3(x * other.x, y * other.y, z * other.z);}
	
	///
	vec3 operator/(const vec3 &other){return vec3(x / other.x, y / other.y, z / other.z);}
	
	///
	vec3 &operator+=(const vec3 &other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	};
	
	///
	vec3 &operator-=(const vec3 &other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	};
	
	///
	vec3 &operator*=(const vec3 &other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	};
	
	///
	vec3 &operator/=(const vec3 &other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	};
	
	///
	float x{0.0f}, y{0.0f}, z{0.0f};
};

}; // namespace konbini::math