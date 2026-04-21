#include "Header_Files/Entity.h"
#include "lib2d/Header_Files/Window.h"

void Entity::Update()
{

}

void Entity::Draw(Window* window)
{
	_sprite->Draw(window);
}

void Entity::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{

}

void Entity::ReScale(float w, float h)
{
	SetWidth(w);
	SetHeight(h);
	_sprite->Resize(w, h);
}

Vector2f Entity::GetHitbox(float anchorX, float anchorY)
{
	return Vector2f({ GetPos().GetX() - width * anchorX, GetPos().GetY() - height * anchorY });
}

void Entity::SetHitbox(Vector2f newPos, float anchorX, float anchorY)
{
	SetPos(Vector2f({ newPos.GetX() + width * anchorX, newPos.GetY() + height * anchorY}));
}