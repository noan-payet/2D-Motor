#include "SquareMob.h"
#include "lib2d/Header_Files/Window.h"

void SquareMob::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(path, GetPos());
	_sprite->loadSprite(window);
	_sprite->Resize(_sprite->GetWidth() * 3, _sprite->GetHeight() * 3);

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;

	_ballPos = Position({ (float)(rand() % (WINDOW_WIDTH)), (float)(rand() % (WINDOW_HEIGHT)) });
}

void SquareMob::Update()
{
	if (GetHitbox(0.f).GetX() > WINDOW_WIDTH)
	{
		_ballPos.SetPos(_ballPos.GetPos().operator=({ -_ballPos.GetPos().GetX(), _ballPos.GetPos().GetY() }));
	}
	else
		if (GetHitbox(0.f).GetX() < 0)
		{
			_ballPos.SetPos(_ballPos.GetPos().operator=({ -_ballPos.GetPos().GetX(), _ballPos.GetPos().GetY() }));
		}

	if (GetHitbox(0.f, 0.f).GetY() > WINDOW_HEIGHT)
	{
		_ballPos.SetPos(_ballPos.GetPos().operator=({ _ballPos.GetPos().GetX(), -_ballPos.GetPos().GetY() }));
	}
	else
		if (GetHitbox(0.f, 0.f).GetY() < 0)
		{
			_ballPos.SetPos(_ballPos.GetPos().operator=({ _ballPos.GetPos().GetX(), -_ballPos.GetPos().GetY() }));
		}

	SetPos(GetPos().operator+(_ballPos.GetPos().Normalise().operator*(5)));
	_sprite->SetPos(GetHitbox());
}
