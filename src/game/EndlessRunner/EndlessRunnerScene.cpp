#include "EndlessRunnerScene.h"
#include "lib2d/Header_Files/Window.h"

#include "game/EndlessRunner/Runner.h"
#include "game/EndlessRunner/Ground.h"

EndlessRunnerScene::EndlessRunnerScene()
{
}

void EndlessRunnerScene::InitScene(Window* window)
{
	CreateEntity<Runner>()->InitEntity(window, "res/game/Runner.png", TARGET_DELTA_TIME, Vector2f({ 100.f, 300.f }));

	float groundCount = 0.f;
	for (int i = 0; i < 5; ++i)
	{
		CreateEntity<Ground>()->InitEntity(window, "res/game/SonicGround.png", TARGET_DELTA_TIME, Vector2f({ groundCount * i, 400.f }));
		groundCount += 120.f;
	}
}

void EndlessRunnerScene::UpdateScene(Window* window)
{
}