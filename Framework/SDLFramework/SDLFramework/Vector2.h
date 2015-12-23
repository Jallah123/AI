#include <math.h>
#include <functional>

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

	Vector2& operator+(const Vector2& other)
	{
		return Vector2{ x + other.x, y + other.y };
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

	Vector2 operator+=(const Vector2& other)
	{
		x = x + other.x;
		y = y + other.y;
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
	double LengthSq()
	{
		return sqrt(x*x + y*y);
	}

	Vector2 Perp()
	{
		return Vector2{ -y, x };
	}
	double Dot(const Vector2& other)
	{
		return x * other.x + y * other.y;
	}
	double Distance(const Vector2& other)
	{
		double lengthX = abs(x - other.x);
		double lengthY = abs(y - other.y);
		return sqrt(lengthX*lengthX + lengthY*lengthY);
	}
};