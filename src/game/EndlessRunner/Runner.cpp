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

	if (_gravity == true)
		jumpCouldown += 0.1f;
	else
		jumpCouldown = 0.f;

	if (jumpCouldown < 3.f)
	{
		if (Input::getInstance().isKeyHeld(SDLK_Z) || Input::getInstance().isKeyHeld(SDLK_UP))
		{
			_playerPos.SetPos({ _playerPos.GetPos().GetX(), -(GetPos().GetY() - 300.f * _deltaTime) });
		}
	}
	if (Input::getInstance().isKeyHeld(SDLK_S) || Input::getInstance().isKeyHeld(SDLK_DOWN) && _gravity == true)
	{
		_playerPos.SetPos({ _playerPos.GetPos().GetX(), GetPos().GetY() + 300.f * _deltaTime });
	}

	_gravity = true;

	SetPos(GetPos().operator+(_playerPos.GetPos().Normalise().operator*(10)));
	_sprite->SetPos(GetPos());

	//std::cout << "Jump cooldown: " << jumpCouldown << std::endl;
	//std::cout << "Player position: (" << GetPos().GetX() << ", " << GetPos().GetY() << ")" << std::endl;
}

void Runner::Draw(Window* window)
{
	_sprite->Draw(window);
}

bool Runner::IsCollding(Entity* otherEntity)
{
	if (GetPos().GetX() + width >= otherEntity->GetPos().GetX() &&                         // r1 right edge past r2 left
		GetPos().GetX() <= otherEntity->GetPos().GetX() + otherEntity->GetWidth() &&       // r1 left edge past r2 right
		GetPos().GetY() + height - 10 >= otherEntity->GetPos().GetY() &&                   // r1 top edge past r2 bottom
		GetPos().GetY() <= otherEntity->GetPos().GetY() + otherEntity->GetHeight())        // r1 bottom edge past r2 top
	{      
		//std::cout << "Collision detected!" << std::endl;
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
