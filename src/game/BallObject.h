#ifndef BALLOBJECT
#define BALLOBJECT

#include "lib2d/Header_Files/Sprite.h"
#include "moteur2d/Header_Files/Entity.h"
#include "lib2d/Header_Files/Window.h"

class BallObject : public Entity
{
private:
	Sprite* _ballSprite = nullptr;
	Position _ballPos = Position();

	float _deltaTime = 0.f;
public:
	BallObject() {}

	void Update() override;
	void Draw(Window* window) override;
	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;
};

#endif

