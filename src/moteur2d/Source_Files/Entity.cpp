#include "Header_Files/Entity.h"
#include "lib2d/Header_Files/Window.h"

void Entity::Update()
{

}

void Entity::Draw(Window* window)
{
	if (_sprite != nullptr)
		_sprite->Draw(window);
}

void Entity::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos(), path);
	_sprite->loadSprite(window);

	_width = _sprite->GetWidth();
	_height = _sprite->GetHeight();

	m_deltaTime = deltaTime;
}

void Entity::ReScale(float w, float h)
{
	_sprite->Resize(w, h);

	SetWidth(_sprite->GetWidth());
	SetHeight(_sprite->GetHeight());
}

Vector2f Entity::GetHitbox(float anchorX, float anchorY)
{
	return Vector2f({ GetPos().GetX() + _width * anchorX, GetPos().GetY() + _height * anchorY });
}

void Entity::SetHitbox(Vector2f newPos, float anchorX, float anchorY)
{
	SetPos(Vector2f({ newPos.GetX() - _width * anchorX, newPos.GetY() - _height * anchorY}));
	_sprite->SetPos(GetPos());
}

bool Entity::IsColliding(Entity* otherEntity)
{
	if (GetHitbox(1.f).GetX() >= otherEntity->GetHitbox(0.f).GetX() &&                         // r1 right edge past r2 left
		GetHitbox(0.f).GetX() <= otherEntity->GetHitbox(1.f).GetX() &&       // r1 left edge past r2 right
		GetHitbox(0.5f, 1.f).GetY() >= otherEntity->GetHitbox(0.5f, 0.f).GetY() &&                   // r1 top edge past r2 bottom
		GetHitbox(0.5f, 0.f).GetY() <= otherEntity->GetHitbox(0.5f, 1.f).GetY())        // r1 bottom edge past r2 top
	{
		//std::cout << "Collision detected!" << std::endl;
		return true;
	}

	return false;
}

bool* Entity::GetCollisionSide(Entity* otherEntity)
{
	// On calcule les distances de pénétration
	float overlapLeft = GetHitbox(0.f).GetX() - otherEntity->GetHitbox(1.f).GetX();
	float overlapRight = otherEntity->GetHitbox(0.f).GetX() - GetHitbox(1.f).GetX();
	float overlapTop = GetHitbox(0.5f, 0.f).GetY() - otherEntity->GetHitbox(0.5f, 1.f).GetY();
	float overlapBottom = otherEntity->GetHitbox(0.5f, 0.f).GetY() - GetHitbox(0.5f, 1.f).GetY();

	overlapLeft *= overlapLeft;
	overlapRight *= overlapRight;
	overlapTop *= overlapTop;
	overlapBottom *= overlapBottom;

	bool side[4] = { true, true, true, true };

	// On cherche la plus petite valeur positive
	float minOverlap = std::min({ overlapLeft, overlapRight, overlapTop, overlapBottom });

	if (minOverlap == overlapLeft)   /* Collision par la GAUCHE de l'obstacle */
		side[2] = false;

	if (minOverlap == overlapRight)  /* Collision par la DROITE de l'obstacle */
		side[3] = false;

	if (minOverlap == overlapTop)    /* Collision par le HAUT de l'obstacle */
		side[0] = false;

	if (minOverlap == overlapBottom) /* Collision par le BAS de l'obstacle */
		side[1] = false;

	return side;
}
