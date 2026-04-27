#include "StrongMan.h"

#include "lib2d/Header_Files/Input.h"

void StrongMan::Update()
{
	Input& input = Input::getInstance();

	if (input.isKeyHeld(SDLK_Z) && direction[0]) {
		SetPos({ GetPos().GetX(), GetPos().GetY() - speed * m_deltaTime });
	}
	else if (input.isKeyHeld(SDLK_S) && direction[1]) {
		SetPos({ GetPos().GetX(), GetPos().GetY() + speed * m_deltaTime });
	}
	else if (input.isKeyHeld(SDLK_Q) && direction[2]) {
		SetPos({ GetPos().GetX() - speed * m_deltaTime, GetPos().GetY() });
	}
	else if (input.isKeyHeld(SDLK_D) && direction[3]) {
		SetPos({ GetPos().GetX() + speed * m_deltaTime, GetPos().GetY() });
	}

	_sprite->SetPos(GetPos());
}

void StrongMan::Collision(std::vector<bool> side)
{
	for (int i = 0; i < 4; ++i)
		direction[i] = side[i];
}

void StrongMan::Push(Entity* otherEntity, std::vector<bool> side)
{
	int sideY = side[0] - side[1];
	int sideX = side[3] - side[2];

	otherEntity->SetPos({ 
		otherEntity->GetPos().GetX() + sideX * speed * m_deltaTime,
		otherEntity->GetPos().GetY() + sideY * speed * m_deltaTime });
}
