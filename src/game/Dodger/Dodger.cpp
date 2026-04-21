#include "Dodger.h"

void Dodger::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);
	_sprite->Resize(_sprite->GetWidth() * 0.25f, _sprite->GetHeight() * 0.25f);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Dodger::Update()
{
	Input& input = Input::getInstance();

	SetPos(input.GetMousePosition());
	_sprite->SetPos(GetHitbox());
}

void Dodger::Draw(Window* window)
{
	_sprite->Draw(window);
}
