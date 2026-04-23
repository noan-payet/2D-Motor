#include "moteur2d/Header_Files/BallObject.h"

BallObject::BallObject(Position pos, Window* window)
{
	_ballEntity = new Entity{ pos };
	_ballSprite = new Sprite{ pos, "..\\..\\res\\moteur2d\\basketBall.png" };
	_ballSprite->Resize(WINDOW_WIDTH / 40, WINDOW_WIDTH / 40);
	_ballSprite->loadSprite(window);
	
}


void BallObject::Update()
{
	if (_ballSprite->GetHitbox(1.f).GetX() > WINDOW_WIDTH)
	{
		_ballSprite->SetHitbox({ -GetPos().GetX(), GetPos().GetY() });
	}
	else
		if (_ballSprite->GetHitbox().GetX() < 0)
		{
			_ballSprite->SetHitbox({ GetPos().GetX(), GetPos().GetY() });
		}

	if (_ballSprite->GetHitbox().GetY() > WINDOW_WIDTH)
	{
		_ballSprite->SetHitbox({ GetPos().GetX(), -GetPos().GetY() });
	}
	else
		if (_ballSprite->GetHitbox().GetY() < 0)
		{
			_ballSprite->SetHitbox({ GetPos().GetX(), GetPos().GetY() });
		}
	Vector2f newPos = { _ballSprite->GetPos().GetX() + GetPos().GetX(), _ballSprite->GetPos().GetY() + GetPos().GetY() };
	_ballSprite->SetPos(newPos);
	SetPos(newPos);
}