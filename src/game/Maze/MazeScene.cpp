#include "MazeScene.h"

#include "lib2d/Header_Files/Window.h"

#include "game/Maze/MazeGenerator.h"

void MazeScene::InitScene(Window* window)
{
	MazeGenerator* mazeGen = CreateEntity<MazeGenerator>();

	int mazeSize = 20;
	float centerX = WINDOW_WIDTH * 1.f / mazeSize;
	float centerY = 50.f;

	mazeGen->InitEntity(window, "", TARGET_DELTA_TIME, { centerX, centerY });
	mazeGen->GenerateMaze(mazeSize, mazeSize);
}

void MazeScene::UpdateScene(Window* window)
{
}
