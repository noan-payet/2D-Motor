#include "MazeGenerator.h"

void MazeGenerator::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos());

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void MazeGenerator::Update()
{
}
