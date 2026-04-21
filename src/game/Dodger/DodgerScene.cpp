#include "DodgerScene.h"

#include "lib2d/Header_Files/Window.h"

#include "Dodger.h"
#include "SquareMob.h"

void DodgerScene::InitScene(Window* window)
{
	CreateEntity<Dodger>()->InitEntity(window, "res/game/Dodger.png", TARGET_DELTA_TIME, Vector2f({ 640.f, 360.f }));
}

void DodgerScene::UpdateScene(Window* window)
{
	int spawnObstacle = rand() % 720 + 720;

	if (spawnObstacle > 700)
		couldown += 10;

	int posX = rand() % 1280 + 1;
	int* pPosX = &posX;

	int posY = rand() % 720 + 1;
	int* pPosY = &posY;

	while (posX > 960 || posX < 320)
		*pPosX = rand() % 1280 + 1;

	while (posY > 540 || posY < 180)
		*pPosY = rand() % 720 + 1;

	if (couldown >= spawnObstacle)
	{
		couldown = 0;
		CreateEntity<SquareMob>()->InitEntity(window, "res/game/SqareMob.png", TARGET_DELTA_TIME, Vector2f({ (float)posX, (float)posY }));
	}
}
