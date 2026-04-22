#include "Clicker.h"

void Clicker::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);
	_sprite->SetAlpha(128);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Clicker::Update()
{
	Input& input = Input::getInstance();
	input.HideMouseCursor();
	SetHitbox(input.GetMousePosition(), 1.f, 1.f);

	_sprite->SetPos(GetHitbox());
}

bool Clicker::Shoot()
{
	Input& input = Input::getInstance();
	return input.IsLeftMouseClick();
}

bool Clicker::Take()
{
	Input& input = Input::getInstance();
	return input.IsRightMouseClick();
}
