#include "ScenePong.h"
#include "lib2d/Header_Files/Window.h"

#include "game/Player.h"
#include "game/BallObject.h"
#include "game/MapManager.h"
#include "game/Bullet.h"

Shoot_them_up::Shoot_them_up(float deltaTime) : deltaTime(deltaTime) {}

void Shoot_them_up::InitScene(Window* window)
{
	CreateEntity<MapManager>()->InitEntity(window, "", TARGET_DELTA_TIME, { 0.f, 0.f });
	CreateEntity<Player>()->InitEntity(window, "res\\game\\Joueur\\Ship.png", TARGET_DELTA_TIME, { 400.f, 300.f });
}

void Shoot_them_up::UpdateScene(Window* window)
{
	if (GetEntity<Player>()->GetStateMachine()->GetState() == (int)Player::PlayerState::SHOOTING)
	{
		CreateEntity<Bullet>()->InitEntity(window, "res\\game\\Missiles\\Beams.png", TARGET_DELTA_TIME, GetEntity<Player>()->GetPos());
	}
}
