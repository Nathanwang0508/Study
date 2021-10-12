#pragma once

#include<string>

using namespace std;

#include<iostream>

class Vector2
{
public:
	float x = 0, y = 0;
public:
	Vector2(float x, float y)
		:x(x), y(y){}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator+ (const Vector2& other)const
	{
		return Add(other);
	}
	Vector2 operator* (const Vector2& other)const
	{
		return Multiply(other);
	}
};
ostream& operator<<(ostream& stream, const Vector2& other)
{
	stream << other.x << "," << other.y;
	return stream;
}
