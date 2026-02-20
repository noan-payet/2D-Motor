#ifndef SCENEBALL
#define SCENEBALL

#include "moteur2d/Header_Files/Scene.h"
#include "game/BallObject.h"

class SceneBall : public Scene
{
private:
	int bulletCouldown = 0;
	int Couldown = 2;

public:
	SceneBall();

	void InitScene(Window* window) override;
	void UpdateScene(Window* window) override;
};
#endif

