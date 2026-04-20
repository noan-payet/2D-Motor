#ifndef _H__RUNNER
#define _H__RUNNER

#include "lib2d/Header_Files/Sprite.h"
#include "lib2d/Header_Files/Input.h"

#include "moteur2d/Header_Files/Entity.h"

class Runner : public Entity
{
private:
	Sprite* _sprite = nullptr;
	float width = 0, height = 0.f;

	float _deltaTime = 0.f;

public:
	Runner() {};
	~Runner() {};

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;
};

#endif // !_H__RUNNER