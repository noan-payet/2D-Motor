#include "Runner.h"

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

	if (Input::getInstance().isKeyHeld(SDLK_Z) || Input::getInstance().isKeyHeld(SDLK_UP))
	{
		_playerPos.SetPos({ _playerPos.GetPos().GetX(), -(GetPos().GetY() - 300.f * _deltaTime) });
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
