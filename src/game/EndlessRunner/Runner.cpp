#include "Runner.h"

#include "game/EndlessRunner/Ground.h"

#include <iostream>

void Runner::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);
	_sprite->Resize(120.f, 120.f);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Runner::Update()
{
	Position _playerPos = Position({ 0.f, 0.f });

	Fall(_playerPos);

	if (Input::getInstance().isKeyHeld(SDLK_Z) || Input::getInstance().isKeyHeld(SDLK_UP))
	{
		_playerPos.SetPos({ _playerPos.GetPos().GetX(), -(GetPos().GetY() - 300.f * _deltaTime) });
		_gravity = true;
	}
	if (Input::getInstance().isKeyHeld(SDLK_S) || Input::getInstance().isKeyHeld(SDLK_DOWN))
	{
		_playerPos.SetPos({ _playerPos.GetPos().GetX(), GetPos().GetY() + 300.f * _deltaTime });
	}

	SetPos(GetPos().operator+(_playerPos.GetPos().Normalise().operator*(10)));
	_sprite->SetPos(GetPos());
}

void Runner::Draw(Window* window)
{
	_sprite->Draw(window);
}

bool Runner::IsCollding(Entity* otherEntity)
{
	if (
		GetPos().GetY() + height >= otherEntity->GetPos().GetY() &&       // r1 top edge past r2 bottom
		GetPos().GetY() <= otherEntity->GetPos().GetY() + otherEntity->GetHeight())		 // r1 bottom edge past r2 top
	{      
		std::cout << "Collision detected!" << std::endl;
		return true;
	}

	return false;
}

void Runner::Fall(Position &player)
{
	if (_gravity == false)
		return;

	player.SetPos({ player.GetPos().GetX(), GetPos().GetY() + 20.f * _deltaTime });
}
