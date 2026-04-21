#include "DodgerScene.h"

#include "lib2d/Header_Files/Window.h"

#include "Dodger.h"
#include "SquareMob.h"

void DodgerScene::InitScene(Window* window)
{
	CreateEntity<Dodger>()->InitEntity(window, "res/game/Dodger.png", TARGET_DELTA_TIME, Vector2f({ 640.f, 360.f }));
}

void DodgerScene::UpdateScene(Window* window)
{
}
