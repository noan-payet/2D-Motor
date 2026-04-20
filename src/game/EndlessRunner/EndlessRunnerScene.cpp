#include "EndlessRunnerScene.h"
#include "lib2d/Header_Files/Window.h"

#include "game/EndlessRunner/Runner.h"
#include "game/EndlessRunner/Ground.h"

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

	_runner = CreateEntity<Runner>();
	_runner->InitEntity(window, "res/game/Runner.png", TARGET_DELTA_TIME, Vector2f({ 100.f, 300.f }));
}

void EndlessRunnerScene::UpdateScene(Window* window)
{
	if (_runner->IsCollding(GetEntity<Ground>()))
		_runner->SetGravity(false);
}