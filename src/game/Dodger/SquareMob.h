#ifndef _H__SQUAREMOB
#define _H__SQUAREMOB

#include "lib2d/Header_Files/Sprite.h"

#include "moteur2d/Header_Files/Entity.h"

class SquareMob : public Entity
{
private:
	Sprite* _sprite = nullptr;

	float _deltaTime = 0.f;

public:
	SquareMob() {};
	~SquareMob() {};

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;
};

#endif // !_H__SQUAREMOB