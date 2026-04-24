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

void StrongMan::Collision(bool* side)
{
	for (int i = 0; i < 4; ++i)
		direction[i] = side[i];
}
