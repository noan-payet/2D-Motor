#include "Ground.h"

void Ground::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos(), path);
	_sprite->loadSprite(window);
	//_sprite->Resize(120.f, 120.f);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Ground::Update()
{
}

void Ground::Draw(Window* window)
{
	_sprite->Draw(window);
}
