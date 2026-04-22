#include "DodgerScene.h"

#include "lib2d/Header_Files/Window.h"

#include "Dodger.h"
#include "SquareMob.h"

void DodgerScene::InitScene(Window* window)
{
	CreateEntity<Entity>()->InitEntity(window, "res/game/Background/Background.png", TARGET_DELTA_TIME, Vector2f({ 0.f, 0.f }));

	CreateEntity<Dodger>()->InitEntity(window, "res/game/Dodger.png", TARGET_DELTA_TIME, Vector2f({ 640.f, 360.f }));
	Dodger* dodger = GetEntity<Dodger>();
	dodger->ReScale(dodger->GetWidth() * 0.25f, dodger->GetHeight() * 0.25f);

	couldown = 0;
	score = 0;
	scoreCouldown = 0;

	playerLife = 3;
	playerInvincibilityCouldown = 0.f;
}

void DodgerScene::UpdateScene(Window* window)
{
	//Score system
	scoreCouldown += 1;
	if (scoreCouldown >= 60)
	{
		score += 1;
		scoreCouldown = 0;
	}

	std::cout << '\n';
	std::cout << "Score: " << score << std::endl;
	std::cout << "Player life: " << playerLife << std::endl;
	std::cout << "Player invincibility cooldown: " << playerInvincibilityCouldown << std::endl;

	//COLISION SYSTEM
	if (playerInvincibilityCouldown > 0.f)
	{
		playerInvincibilityCouldown -= 0.1f;
	}

	for (auto& o : GetEntities<SquareMob>())
	{
		if (GetEntity<Dodger>()->IsColliding(o) && playerInvincibilityCouldown <= 0.f)
		{
			o = nullptr;

			playerInvincibilityCouldown = 5.f;
			playerLife -= 1;
			GetEntity<Dodger>()->LoseLife();
		}
	}

	if (playerLife <= 0)
	{
		system("cls");
		std::cout << '\n' << '\n';
		std::cout << "Game Over!" << std::endl;
		std::cout << "Your score: " << score << std::endl;
		QuitScene();
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
	while (posX > WINDOW_WIDTH * 7/8 || posX < WINDOW_WIDTH * 1/8)
		*pPosX = rand() % WINDOW_WIDTH + 1;

	while (posY > WINDOW_HEIGHT * 7/8 || posY < WINDOW_HEIGHT * 1/8)
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
