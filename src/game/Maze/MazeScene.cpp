#include "MazeScene.h"

#include "lib2d/Header_Files/Window.h"

#include "game/Maze/MazeGenerator.h"

void MazeScene::InitScene(Window* window)
{
	CreateEntity<MazeGenerator>()->InitEntity(window, "", TARGET_DELTA_TIME, { 253.2f, 50.f });
	GetEntity<MazeGenerator>()->GenerateMaze(5, 5);
}

void MazeScene::UpdateScene(Window* window)
{
}
