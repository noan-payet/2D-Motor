#ifndef _H__OBSTACLE
#define _H__OBSTACLE

#include "lib2d/Header_Files/Sprite.h"

#include "moteur2d/Header_Files/Entity.h"

class Obstacle : public Entity
{
private:
	Sprite* _sprite = nullptr;

	float _deltaTime = 0.f;

public:
	Obstacle() {};
	~Obstacle() {};

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;
};

#endif // !_H__OBSTACLE