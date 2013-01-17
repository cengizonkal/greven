#ifndef _H_VECTOR
#define _H_VECTOR

# include <math.h>
struct Cvector
{
	/// Default constructor does nothing (for performance).

	Cvector() {}

	/// Construct using coordinates.
	Cvector(float x, float y) : x(x), y(y) {}

	/// Set this vector to all zeros.
	void SetZero() { x = 0.0f; y = 0.0f; }

	/// Set this vector to some specified coordinates.
	void Set(float x_, float y_) { x = x_; y = y_; }

	/// Negate this vector.
	Cvector operator -() const
	{
	    Cvector v;
	    v.Set(-x, -y);
	    return v;
	}

	/// Read from and indexed element.
	float operator () (int i) const
	{
		return (&x)[i];
	}

	/// Write to an indexed element.
	float& operator () (int i)
	{
		return (&x)[i];
	}

	/// Add a vector to this vector.
	void operator += (const Cvector& v)
	{
		x += v.x; y += v.y;
	}

	/// Subtract a vector from this vector.
	void operator -= (const Cvector& v)
	{
		x -= v.x; y -= v.y;
	}

	/// Multiply this vector by a scalar.
	void operator *= (float a)
	{
		x *= a; y *= a;
	}

	/// Get the length of this vector (the norm).
	float Length() const
	{
		return sqrt(x * x + y * y);
	}

	/// Get the length squared. For performance, use this instead of
	/// Cvector::Length (if possible).
	float LengthSquared() const
	{
		return x * x + y * y;
	}

	/// Convert this vector into a unit vector. Returns the length.
	float Normalize()
	{
		float length = Length();
		if (length < 0)
		{
			return 0.0f;
		}
		float invLength = 1.0f / length;
		x *= invLength;
		y *= invLength;

		return length;
	}

	/// Does this vector contain finite coordinates?
	bool IsValid() const
	{
		return true;
	}

	/// Get the skew vector such that dot(skew_vec, other) == cross(vec, other)
	Cvector Skew() const
	{
		return Cvector(-y, x);
	}

	float x, y;
};

inline Cvector operator + (const Cvector& a, const Cvector& b)
{
	return Cvector(a.x + b.x, a.y + b.y);
}

/// Subtract two vectors component-wise.
inline Cvector operator - (const Cvector& a, const Cvector& b)
{
	return Cvector(a.x - b.x, a.y - b.y);
}

inline Cvector operator * (float s, const Cvector& a)
{
	return Cvector(s * a.x, s * a.y);
}

inline bool operator == (const Cvector& a, const Cvector& b)
{
	return a.x == b.x && a.y == b.y;
}
#endif
