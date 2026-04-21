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
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();
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

bool Entity::IsCollding(Entity* otherEntity)
{
	if (GetPos().GetX() + width >= otherEntity->GetPos().GetX() &&                         // r1 right edge past r2 left
		GetPos().GetX() <= otherEntity->GetPos().GetX() + otherEntity->GetWidth() &&       // r1 left edge past r2 right
		GetPos().GetY() + height - 10 >= otherEntity->GetPos().GetY() &&                   // r1 top edge past r2 bottom
		GetPos().GetY() <= otherEntity->GetPos().GetY() + otherEntity->GetHeight())        // r1 bottom edge past r2 top
	{
		std::cout << "Collision detected!" << std::endl;
		return true;
	}

	return false;
}