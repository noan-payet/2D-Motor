#include "MazeScene.h"

#include "lib2d/Header_Files/Window.h"

#include "game/Maze/MazeGenerator.h"

void MazeScene::InitScene(Window* window)
{
	MazeGenerator* mazeGen = CreateEntity<MazeGenerator>();

	int mazeSize = 20;
	mazeGen->GenerateMaze(mazeSize, mazeSize);

	float centerX = (WINDOW_WIDTH - mazeGen->GetWidth()) / 2.f;
	float centerY = (WINDOW_HEIGHT - mazeGen->GetHeight()) / 2.f;

	mazeGen->InitEntity(window, "", TARGET_DELTA_TIME, { centerX - 35.f, centerY });

	Entity* entity = CreateEntity<Entity>();
	entity->InitEntity(window, "res/game/white_circle.png", TARGET_DELTA_TIME, { 640.f, 400.f });
	entity->ReScale(40.f, 40.f);
	entity->SetHitbox({ 640.f, 400.f });
}

void MazeScene::UpdateScene(Window* window)
{

}