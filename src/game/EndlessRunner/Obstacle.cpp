#include "Obstacle.h"
#include "lib2d/Header_Files/Window.h"

void Obstacle::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos(), path);
	_sprite->loadSprite(window);
	_sprite->Resize(75.f, 95.f);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Obstacle::Update()
{
	if (GetPos().GetX() <= 10.f)
	{
		SetPos({ -30.f, GetPos().GetY() });
		return;
	}

	Position Pos = Position({ 0.f, 0.f });

	Pos.SetPos({ -(GetPos().GetX() + 300.f * _deltaTime), 0.f });

	SetPos(GetPos().operator+(Pos.GetPos().Normalise().operator*(10)));
	_sprite->SetPos(GetPos());
}

void Obstacle::Draw(Window* window)
{
	if (_sprite != nullptr)
		_sprite->Draw(window);
}
