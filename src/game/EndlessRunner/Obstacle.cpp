#include "Obstacle.h"
#include "lib2d/Header_Files/Window.h"

void Obstacle::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);
	_sprite->Resize(75.f, 95.f);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Obstacle::Update()
{
	Position Pos = Position({ 0.f, 0.f });

	Pos.SetPos({ -(GetPos().GetX() + 300.f * _deltaTime), 0.f });

	SetPos(GetPos().operator+(Pos.GetPos().Normalise().operator*(10)));
	_sprite->SetPos(GetPos());
}

void Obstacle::Draw(Window* window)
{
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_FRect rect = { GetPos().GetX(), GetPos().GetY(), width, height };
	SDL_RenderRect(window->GetRenderer(), &rect);

	_sprite->Draw(window);
}
