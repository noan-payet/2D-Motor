#ifndef _H__CLICKER
#define _H__CLICKER

#include "lib2d/Header_Files/Sprite.h"
#include "lib2d/Header_Files/Input.h"

#include "moteur2d/Header_Files/Entity.h"

class Clicker : public Entity
{
private:
	float _deltaTime = 0.f;

public:
	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

public:
	bool Shoot();
};

#endif // !_H__CLICKER