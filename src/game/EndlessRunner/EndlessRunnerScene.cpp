#include "EndlessRunnerScene.h"
#include "lib2d/Header_Files/Window.h"

#include "game/EndlessRunner/Runner.h"
#include "game/EndlessRunner/Ground.h"
#include "game/EndlessRunner/Obstacle.h"

EndlessRunnerScene::EndlessRunnerScene()
{
}

void EndlessRunnerScene::InitScene(Window* window)
{
	float groundCount = 250.f;
	for (int i = 0; i < 6; ++i)
	{
		CreateEntity<Ground>()->InitEntity(window, "res/game/SonicGround.png", TARGET_DELTA_TIME, Vector2f({ groundCount * i, 400.f }));
	}

	CreateEntity<Obstacle>()->InitEntity(window, "res/game/Taxes.png", TARGET_DELTA_TIME, Vector2f({ 720.f, 300.f }));

	CreateEntity<Runner>()->InitEntity(window, "res/game/Runner.png", TARGET_DELTA_TIME, Vector2f({ 100.f, 300.f }));
}

void EndlessRunnerScene::UpdateScene(Window* window)
{
	if (GetEntities<Ground>().size() > 0)
	{
		for (auto& o : GetEntities<Ground>())
		{
			if (GetEntity<Runner>()->IsCollding(o))
			{
				GetEntity<Runner>()->SetGravity(false);
			}
		}
	}

	/*for (std::size_t i = obstacles.size(); i > 0; --i)
	{
		std::size_t idx = i - 1;
		if (obstacles[idx]->GetPos().GetX() <= 0.f)
		{
			std::cout << "Obstacle removed!" << std::endl;
			GetEntities<Obstacle>().at(idx)->~Obstacle();
			obstacles.erase(obstacles.begin() + idx);
		}
	}*/
	int spawnObstacle = rand() % 720 + 720;

	if (spawnObstacle > 700 && couldown == 0)
		couldown += 100;

	if (couldown >= spawnObstacle)
	{
		couldown = 0;
		CreateEntity<Obstacle>()->InitEntity(window, "res/game/Taxes.png", TARGET_DELTA_TIME, Vector2f({ 720.f, 300.f }));
	}
	
	if (GetEntities<Obstacle>().size() > 0)
	{
		for (auto& o : GetEntities<Obstacle>())
		{
			if (GetEntity<Runner>()->IsCollding(o))
			{
				std::cout << "Game Over!" << std::endl;
				exit(0);
			}
		}
	}
}