#ifndef _H__SQUAREMOB
#define _H__SQUAREMOB

#include "lib2d/Header_Files/Sprite.h"

#include "moteur2d/Header_Files/Entity.h"

class SquareMob : public Entity
{
private:
	Position _ballPos = Position();

	float _deltaTime = 0.f;

public:
	SquareMob() {};
	~SquareMob() {};

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

private:
	float life = 1;

public:
	void LoseLife(int attack) { life -= attack; }
	void SetLife(float life) { this->life = life; }
	float GetLife() { return life; }
};

#endif // !_H__SQUAREMOB