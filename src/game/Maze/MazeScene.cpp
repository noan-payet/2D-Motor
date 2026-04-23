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

	mazeGen->InitEntity(window, "", TARGET_DELTA_TIME, { centerX, centerY });
}

void MazeScene::UpdateScene(Window* window)
{
}