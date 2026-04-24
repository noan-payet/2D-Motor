#include "MazeScene.h"

#include "lib2d/Header_Files/Window.h"

#include "game/Maze/MazeGenerator.h"
#include "game/Maze/ManInMaze.h"

void MazeScene::InitScene(Window* window)
{
	MazeGenerator* mazeGen = CreateEntity<MazeGenerator>();

	int mazeSize = 20;
	mazeGen->GenerateMaze(mazeSize, mazeSize);

	float centerX = (WINDOW_WIDTH - mazeGen->GetWidth()) / 2.f;
	float centerY = (WINDOW_HEIGHT - mazeGen->GetHeight()) / 2.f;

	mazeGen->InitEntity(window, "", TARGET_DELTA_TIME, { centerX - 35.f, centerY });

	ManInMaze* entity = CreateEntity<ManInMaze>();
	entity->InitEntity(window, "res/game/white_circle.png", TARGET_DELTA_TIME, { 640.f, 400.f });
	entity->ReScale(40.f, 40.f);
	entity->SetHitbox({ 640.f, 400.f });
}

void MazeScene::UpdateScene(Window* window)
{
	ManInMaze* entity = GetEntity<ManInMaze>();
	MazeGenerator* mazeGen = GetEntity<MazeGenerator>();

	if (GetPixelOnScreen<Entity>(window, { entity->GetHitbox(0.f, 0.5f).GetX() - 4, entity->GetHitbox(0.f, 0.5f).GetY() }, 4) != 0)
	{
		std::cout << "Left" << std::endl;
		mazeGen->Collision(2, false);
	}
	else
	{
		mazeGen->Collision(2, true);
	}

	if (GetPixelOnScreen<Entity>(window, entity->GetHitbox(1.f, 0.5f), 4) != 0)
	{
		mazeGen->Collision(3, false);
	}
	else
	{
		mazeGen->Collision(3, true);
	}

	if (GetPixelOnScreen<Entity>(window, { entity->GetHitbox().GetX(), entity->GetHitbox(0.5f, 0.f).GetY() - 4 }, 4) != 0)
	{
		std::cout << "Up" << std::endl;
		mazeGen->Collision(0, false);
	}
	else
	{
		mazeGen->Collision(0, true);
	}

	if (GetPixelOnScreen<Entity>(window, entity->GetHitbox(0.5f, 1.f), 4) != 0)
	{
		mazeGen->Collision(1, false);
	}
	else
		{
		mazeGen->Collision(1, true);
	}
}