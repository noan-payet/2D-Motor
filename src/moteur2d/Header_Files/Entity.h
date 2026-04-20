#ifndef ENTITY
#define ENTITY

#include "lib2d/Header_Files/Position.h"
#include "lib2d/Header_Files/Drawable.h"


class Entity : public Position, public Drawable
{
protected:
	float width = 0.f, height = 0.f;

public:
	Entity(Position pos):
		Position(pos) {}
	Entity() :
		Position() {}

	virtual void Update();

	virtual void Draw(Window* window) override;

	virtual void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos);

public:
	float GetWidth() { return width; }
	float GetHeight() { return height; }
};

#endif

