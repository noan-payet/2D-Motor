#include "SceneBall.h"

SceneBall::SceneBall()
{
}

void SceneBall::InitScene(Window* window)
{

}

void SceneBall::UpdateScene(Window* window)
{
	if (!Input::getInstance().isKeyHeld(SDLK_B))
	{
		return;
	}

	bulletCouldown++;

	int restCouldown = Couldown;

	Couldown *= 4;
	int CouldownLimit = bulletCouldown % Couldown;

	Couldown = restCouldown;

	if (CouldownLimit == 0)
	{
		CreateEntity<BallObject>()->InitEntity(window, "res\\game\\basketBall.png", TARGET_DELTA_TIME, { (float)(rand() % (WINDOW_WIDTH - 50) + 1), (float)(rand() % (WINDOW_HEIGHT - 50) + 1) });
		bulletCouldown = 0;
	}
}