#pragma once
#include <math.h>

class ForceDrivenEntity;
struct Vector2
{
	float x;
	float y;

	float Length()
	{
		return sqrt(x * x + y * y);
	}

	void Normalize()
	{
		float length = Length();
		if (length != 0)
		{
			x = x / length;
			y = y / length;
		}
	}

	void Truncate(float maxValue)
	{
		if (x > maxValue)
		{
			x = maxValue;
		}
		else if (fabsf(x) > maxValue)
		{
			x = -maxValue;
		}

		if (y > maxValue)
		{
			y = maxValue;
		}
		else if (fabsf(y) > maxValue)
		{
			y = -maxValue;
		}
	}

	Vector2& operator-(const Vector2& other) 
	{
		return Vector2{ x - other.x, y - other.y };
	}

	Vector2& operator*(const Vector2& other)
	{
		return Vector2{ x * other.x, y * other.y };
	}

	Vector2 operator*=(const Vector2& other)
	{
		x = x * other.x;
		y = y * other.y;
		return *this;
	}

	Vector2& operator*(const float& multiplier)
	{
		return Vector2{ x * multiplier, y * multiplier };
	}

	Vector2 operator*=(const float& multiplier)
	{
		this->operator*=(Vector2{ multiplier, multiplier });
		return *this;
	}
};

class SteeringBehaviour
{
public:
	SteeringBehaviour() { };
	void SetOwner(ForceDrivenEntity* newowner) { owner = newowner; };
	virtual Vector2 Calculate() { return Seek(Vector2{ 300, 400 }); };
	Vector2 Seek(Vector2 Target);
	~SteeringBehaviour();
private:
	ForceDrivenEntity* owner;
};

