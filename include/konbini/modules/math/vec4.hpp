/*
 *	This file is part of konbinilib
 *	Copyright (C) 2018-2019 BlackPhrase
 */

/// @file
/// @brief 4d vector class

#pragma once

namespace konbini::math
{

//template<typename T>
class vec4 final
{
public:
	//{ Static members
	
	static vec4 zero = {0.0f};
	
	//}
	
	//{ Constructors
	
	///
	vec4() : vec4(0.0f){}
	
	///
	vec4(float value) : vec4(value, value, value, value){}
	
	///
	vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}
	
	//}
	
	//{ Methods
	
	float length() const {return sqrt(x*x + y*y + z*z + w*w);}
	
	//}
	
	//{ Operator overloading
	
	///
	bool operator==(const vec4 &other) const
	{
		if(x == other.x && y == other.y && z == other.z && w == other.w)
			return true;
		
		return false;
	};
	
	///
	bool operator!=(const vec4 &other) const {return !(*this == other);}
	
	///
	vec4 operator+(const vec4 &other) const {return vec4(x + other.x, y + other.y, z + other.z, w + other.w);}
	
	///
	vec4 operator-(const vec4 &other) const {return vec4(x - other.x, y - other.y, z - other.z, w - other.w);}
	
	///
	vec4 operator*(const vec4 &other) const {return vec4(x * other.x, y * other.y, z * other.z, w * other.w);}
	
	///
	vec4 operator/(const vec4 &other) const {return vec4(x / other.x, y / other.y, z / other.z, w / other.w);}
	
	///
	vec4 &operator+=(const vec4 &other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	};
	
	///
	vec4 &operator-=(const vec4 &other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	};
	
	///
	vec4 &operator*=(const vec4 &other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	};
	
	///
	vec4 &operator/=(const vec4 &other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	};
	
	//}
	
	//{ Data
	
	///
	float x{0.0f}, y{0.0f}, z{0.0f}, w{0.0f};
	
	//}
};

}; // namespace konbini::math