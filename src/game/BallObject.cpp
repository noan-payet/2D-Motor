#include "game/BallObject.h"
#include "lib2d/Header_Files/Window.h"

void BallObject::Update()
{
	if (_ballSprite->GetHitbox(1.f).GetX() > WINDOW_WIDTH)
	{
		_ballPos.SetPos(_ballPos.GetPos().operator=({ -_ballPos.GetPos().GetX(), _ballPos.GetPos().GetY() }));
	}
	else
	if (_ballSprite->GetHitbox().GetX() < 0)
	{
		_ballPos.SetPos(_ballPos.GetPos().operator=({ -_ballPos.GetPos().GetX(), _ballPos.GetPos().GetY() }));
	}

	if (_ballSprite->GetHitbox(0.f, 1.f).GetY() > WINDOW_HEIGHT)
	{
		_ballPos.SetPos(_ballPos.GetPos().operator=({ _ballPos.GetPos().GetX(), -_ballPos.GetPos().GetY() }));
	}
	else
	if (_ballSprite->GetHitbox().GetY() < 0)
	{
		_ballPos.SetPos(_ballPos.GetPos().operator=({ _ballPos.GetPos().GetX(), -_ballPos.GetPos().GetY() }));
	}

	_ballSprite->SetPos(_ballSprite->GetPos().operator+(_ballPos.GetPos().Normalise().operator*(5)));
}

void BallObject::Draw(Window* window)
{
	_ballSprite->Draw(window);
}

void BallObject::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	_ballSprite = new Sprite{ pos, path };
	_ballSprite->loadSprite(window);
	_ballSprite->Resize(50, 50);

	_ballPos.SetPos(_ballSprite->GetPos());

	_deltaTime = deltaTime;
}