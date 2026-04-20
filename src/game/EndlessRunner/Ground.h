#ifndef _H__GROUND
#define _H__GROUND

#include "lib2d/Header_Files/Sprite.h"

#include "moteur2d/Header_Files/Entity.h"

class Ground : public Entity
{
private:
	Sprite* _sprite = nullptr;
	float width = 0, height = 0.f;

	float _deltaTime = 0.f;

public:
	Ground() {};
	~Ground() {};

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;
};

#endif // !_H__GROUND