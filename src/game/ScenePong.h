#ifndef PONG
#define PONG

#include "moteur2d/Header_Files/Scene.h"

class Shoot_them_up : public Scene
{
private:
	float deltaTime;

	int bulletCouldown = 0;
	int Couldown = 4;

public:
	Shoot_them_up(float deltaTime);

	void InitScene(Window* window) override;
	void UpdateScene(Window* window) override;
};

#endif // !PONG
