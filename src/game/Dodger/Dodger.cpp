#include "Dodger.h"

void Dodger::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_spriteLife = new Sprite("res/game/Life.png", GetHitbox(0.75f, 1.f), true);
	_spriteLife->loadSprite(window);
	_spriteLife->Resize(_spriteLife->GetWidth() * 0.25f, _spriteLife->GetHeight() * 0.25f);

	_spriteLife->SetWidth(_spriteLife->GetWidth() / 3);

	_deltaTime = deltaTime;
}

void Dodger::Update()
{
	Input& input = Input::getInstance();
	input.HideMouseCursor();
	SetHitbox(input.GetMousePosition(), 1.f, 1.f);

	_sprite->SetPos(GetHitbox());
	_spriteLife->SetPos(GetHitbox(1.f, 1.f));
}

void Dodger::Draw(Window* window)
{
	_sprite->Draw(window);
	_spriteLife->Draw(window);
}

void Dodger::LoseLife()
{
	++life; 
	_spriteLife->SetSizeX(_spriteLife->GetOriginalWidth() * life / 4);
}