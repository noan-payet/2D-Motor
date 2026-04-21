#include "SquareMob.h"

void SquareMob::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);
	_sprite->Resize(120.f, 120.f);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void SquareMob::Update()
{
}

void SquareMob::Draw(Window* window)
{
}
