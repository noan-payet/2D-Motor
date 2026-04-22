#include "ClickerScene.h"

#include "lib2d/Header_Files/Window.h"

#include "game/Clicker/Clicker.h"
#include "game/Dodger/SquareMob.h"

void ClickerScene::InitScene(Window* window)
{
	CreateEntity<Clicker>()->InitEntity(window, "res/game/camera.png", TARGET_DELTA_TIME, Vector2f({ 640.f, 360.f }));
	GetEntity<Clicker>()->SetPriority(-1);
}

void ClickerScene::UpdateScene(Window* window)
{
	// Collision
	Clicker* clicker = GetEntity<Clicker>();
	for (auto& o : GetEntities<SquareMob>())
	{
		if (GetEntity<Clicker>()->IsCollding(o) && clicker->Shoot())
		{
			o = nullptr;
			std::cout << "Shoot !\n";
		}
	}

	//Spawn system
	int spawnObstacle = rand() % WINDOW_HEIGHT + 720;

	if (spawnObstacle > 700)
		couldown += 10;

	int posX = rand() % WINDOW_WIDTH + 1;
	int* pPosX = &posX;

	int posY = rand() % WINDOW_HEIGHT + 1;
	int* pPosY = &posY;

	//Faire Spawn les mobs dans la partie extérieur de la fenetre pour eviter les spawn injustes
	while (posX > WINDOW_WIDTH * 7 / 8 || posX < WINDOW_WIDTH * 1 / 8)
		*pPosX = rand() % WINDOW_WIDTH + 1;

	while (posY > WINDOW_HEIGHT * 7 / 8 || posY < WINDOW_HEIGHT * 1 / 8)
		*pPosY = rand() % WINDOW_HEIGHT + 1;

	if (couldown >= spawnObstacle)
	{
		couldown = 0;
		SquareMob* mob = CreateEntity<SquareMob>();
		mob->InitEntity(window, "res/game/SqareMob.png", TARGET_DELTA_TIME, Vector2f({ (float)posX, (float)posY }));

		float size = rand() % 3 + 1;
		mob->ReScale(mob->GetWidth() * size, mob->GetHeight() * size);
	}
}
