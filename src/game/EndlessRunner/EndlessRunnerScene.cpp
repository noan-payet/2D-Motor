#include "EndlessRunnerScene.h"
#include "lib2d/Header_Files/Window.h"

#include "moteur2d/Header_Files/RunningGame.h"

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

	//CreateEntity<Obstacle>()->InitEntity(window, "res/game/Taxes.png", TARGET_DELTA_TIME, Vector2f({ 720.f, 300.f }));

	CreateEntity<Runner>()->InitEntity(window, "res/game/Runner.png", TARGET_DELTA_TIME, Vector2f({ 100.f, 300.f }));
}

void EndlessRunnerScene::UpdateScene(Window* window)
{
	std::cout << "Score: " << score << std::endl;

	if (GetEntities<Ground>().size() > 0)
	{
		for (auto& o : GetEntities<Ground>())
		{
			if (GetEntity<Runner>()->IsColliding(o))
			{
				GetEntity<Runner>()->SetGravity(false);
				GetEntity<Runner>()->SetPos({ GetEntity<Runner>()->GetPos().GetX(), 290.f });
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

	for (auto& o : GetEntities<Obstacle>())
	{
		float distance = o->GetPos().GetX() - GetEntity<Runner>()->GetPos().GetX();

		if (distance <= 0.5f && distance >= -0.5f)
		{
			score += 1;
		}
	}

	int spawnObstacle = rand() % 720 + 720;

	if (spawnObstacle > 700)
		couldown += 10;

	if (couldown >= spawnObstacle)
	{
		couldown = 0;
		CreateEntity<Obstacle>()->InitEntity(window, "res/game/Taxes.png", TARGET_DELTA_TIME, Vector2f({ 1280.f, 300.f }));
	}

	for (auto& o : GetEntities<Obstacle>())
	{
		if (GetEntity<Runner>()->IsColliding(o))
		{ 
			std::cout << '\n' << '\n';
			std::cout << "Game Over!" << std::endl;
			std::cout << "Your score: " << score << std::endl;
			
			QuitScene();
		}
	}
}