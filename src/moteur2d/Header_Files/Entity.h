#ifndef ENTITY
#define ENTITY

#include "lib2d/Header_Files/Position.h"
#include "lib2d/Header_Files/Drawable.h"
#include "lib2d/Header_Files/Sprite.h"

#include <vector>

class Entity : public Position, public Drawable
{
protected:
	Sprite* _sprite = nullptr;

	float _width = 0.f, _height = 0.f;
	float m_deltaTime = 0.f;
	float higher = 0.f, widther = 0.f;;

	int priority = 0;

	std::string _type = "Entity";

	bool DEBUG = false;

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
	void DrawHitbox(Window* window, Uint8 alpha = 255);
	void SetDebug(bool debug) { DEBUG = debug; }

	void SetType(std::string type) { _type = type; }
	std::string GetType() const { return _type; }

	int GetPriority() const { return priority; }
	void SetPriority(int p) { priority = p; }

	Sprite* GetSprite() { return _sprite; }

	float GetWidth() { return _width; }
	float GetHeight() { return _height; }

	void SetWidth(float width)   { this->_width = width; }
	void SetHeight(float height) { this->_height = height; }

	void SetHeigher(float height) { higher = height; _height -= higher; }
	void SetWighter(float width) { widther = width; _width -= widther; }

	void ReScale(float w, float h);

	Vector2f GetHitbox(float anchorX = 0.5f, float anchorY = 0.5f);
	void SetHitbox(Vector2f newPos, float anchorX = 0.5f, float anchorY = 0.5f);

	bool IsColliding(Entity* otherEntity);
	std::vector<bool> GetCollisionSide(Entity* otherEntity);
};

#endif

