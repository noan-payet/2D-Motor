#ifndef VECTOR2F
#define VECTOR2F

class Vector2f
{
private:
	float _x;
	float _y;

public:
	Vector2f() :_x(0.0f), _y(0.0f) { }
	Vector2f(float x, float y) :_x(x), _y(y) { }

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	Vector2f Normalise();

	//float GetDistance(float x1, float y1, float x2, float y2);

	Vector2f operator-(const Vector2f& _right);
	Vector2f operator+(const Vector2f& _right);
	Vector2f operator*(float _right);
};

#endif

