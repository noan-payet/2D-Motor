#ifndef _H__DODGERSCENE
#define _H__DODGERSCENE

#include "moteur2d/Header_Files/Scene.h"

class DodgerScene : public Scene
{
private:
	int couldown = 0;
	int score = 0;
	int scoreCouldown = 0;

	int playerLife = 3;
	float playerInvincibilityCouldown = 0.f;

public:
	DodgerScene() {};

	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__DODGERSCENE