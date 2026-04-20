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

	CreateEntity<Obstacle>()->InitEntity(window, "res/game/Taxes.png", TARGET_DELTA_TIME, Vector2f({ 500.f, 300.f }));

	CreateEntity<Runner>()->InitEntity(window, "res/game/Runner.png", TARGET_DELTA_TIME, Vector2f({ 100.f, 300.f }));
}

void EndlessRunnerScene::UpdateScene(Window* window)
{
	if (GetEntity<Runner>()->IsCollding(GetEntity<Ground>()))
		GetEntity<Runner>()->SetGravity(false);

	if (GetEntities<Obstacle>().size() <= 0)
		return;

	for (int i = GetEntities<Obstacle>().size() - 1; i >= 0; --i)
	{
		if (GetEntities<Obstacle>()[i]->GetPos().GetX() <= 0.f)
		{
			GetEntities<Obstacle>().erase(GetEntities<Obstacle>().begin() + i);
		}
	}
	
	/*
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
	}*/
}