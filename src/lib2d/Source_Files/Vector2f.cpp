#include "Header_Files/Vector2f.h"
#include <math.h>

float Vector2f::GetX()
{
	return _x;
}
float Vector2f::GetY()
{
	return _y;
}

void Vector2f::SetX(float x)
{
	_x = x;
}
void Vector2f::SetY(float y)
{
	_y = y;
}

Vector2f Vector2f::Normalise()
{
    float d = sqrt(pow(_x, 2) + pow(_y, 2));

    if (d == 0)
        return Vector2f(0, 0);

    float x = _x / d;
    float y = _y / d;

    return Vector2f(x, y);
}

/*
float GetDistance(float x1, float y1, float x2, float y2)
{
    float distanceX = (x1 - x2) * (x1 - x2);
    float distanceY = (y1 - y2) * (y1 - y2);
    float distance = sqrt(distanceX + distanceY);
	return distance;
}
*/

Vector2f Vector2f::operator-(const Vector2f& _right) {
    return Vector2f(_x - _right._x, _y - _right._y);
}

Vector2f Vector2f::operator+(const Vector2f& _right) {
    return Vector2f(_x + _right._x, _y + _right._y);
}

Vector2f Vector2f::operator*(float _right) {
    return Vector2f(_x * _right, _y * _right);
}