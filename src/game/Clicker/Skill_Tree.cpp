#include "Skill_Tree.h"

void Skill_Tree::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos(), path);
	_sprite->loadSprite(window);

	_width = _sprite->GetWidth();
	_height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void Skill_Tree::Update()
{

}