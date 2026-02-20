#include "Header_Files/Position.h"

Vector2f Position::GetPos()
{
	return _position;
}
void Position::SetPos(Vector2f newPos)
{
	_position = newPos;
}

void Position::Movefloat(float deltaX, float deltaY)
{
	SetPos({ GetPos().GetX() + deltaX, GetPos().GetY() + deltaY });
}
