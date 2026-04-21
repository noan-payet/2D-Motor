#ifndef _H__DODGER
#define _H__DODGER

#include "lib2d/Header_Files/Sprite.h"
#include "lib2d/Header_Files/Input.h"

#include "moteur2d/Header_Files/Entity.h"

class Dodger : public Entity
{
private:
	Sprite* _sprite = nullptr;

	float _deltaTime = 0.f;

public:
	Dodger() {};
	~Dodger() {};

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;
};

#endif // !_H__DODGER