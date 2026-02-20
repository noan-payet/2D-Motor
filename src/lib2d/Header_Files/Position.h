#ifndef POSITION
#define POSITION

#include "lib2d/Header_Files/Vector2f.h"
class Position
{
protected:
	Vector2f _position;
public:
	Position()
		:_position(Vector2f()) { }

	Position(Vector2f pos)
		:_position(pos) { }
	
	Vector2f GetPos();
	void SetPos(Vector2f newPos);

	void Movefloat(float deltaX, float deltaY);
};

#endif
