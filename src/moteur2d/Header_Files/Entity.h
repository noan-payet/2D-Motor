#ifndef ENTITY
#define ENTITY

#include "lib2d/Header_Files/Position.h"
#include "lib2d/Header_Files/Drawable.h"
#include "lib2d/Header_Files/Sprite.h"


class Entity : public Position, public Drawable
{
protected:
	Sprite* _sprite = nullptr;

	float width = 0.f, height = 0.f;

	int priority = 0;

public:
	Entity(Position pos):
		Position(pos) {

	}
	Entity() :
		Position() {}

	virtual void Update();

	virtual void Draw(Window* window) override;

	virtual void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos);

public:
	int GetPriority() const { return priority; }
	void SetPriority(int p) { priority = p; }

	Sprite* GetSprite() { return _sprite; }

	float GetWidth() { return width; }
	float GetHeight() { return height; }

	void SetWidth(float width)   { this->width = width; }
	void SetHeight(float height) { this->height = height; }

	void ReScale(float w, float h);

	Vector2f GetHitbox(float anchorX = 0.5f, float anchorY = 0.5f);
	void SetHitbox(Vector2f newPos, float anchorX = 0.5f, float anchorY = 0.5f);

	bool IsColliding(Entity* otherEntity);
};

#endif

