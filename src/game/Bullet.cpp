#include "Bullet.h"

bool Bullet::Coliding(Sprite* target)
{
	Vector2f center1 = _bulletImage->GetHitbox(0.5f, 0.5f);
	Vector2f center2 = target->GetHitbox(0.5f, 0.5f);

	int getRadius = _bulletImage->GetWidth() / 2;
	int GetTargetRadius = target->GetWidth() / 2;

	Vector2f diff = { 0.f, 0.f };

	//float distance = diff.GetDistance(center1.GetX(), center1.GetY(), center2.GetX(), center2.GetY());
	float radiusDist = getRadius + GetTargetRadius;

	//return distance <= radiusDist;
	return true;
}

void Bullet::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	_bulletImage = new Sprite{ pos, path };
	_bulletImage->loadSprite(window);
	_bulletImage->Resize(_bulletImage->GetWidth(), _bulletImage->GetHeight());
	_bulletImage->SetPos(_bulletImage->GetHitbox(0.f, 0.5f));

   	this->_deltaTime = deltaTime;
}

void Bullet::Update()
{
	_bulletImage->Movefloat(_speedBullet * _deltaTime, 0.f );
}
/*
void Bullet::Pathfinding(Sprite* target)
{
	Vector2f EnemyPos = target->GetHitbox(0.5f, 0.5f);
	Vector2f BulletPos = _bulletImage->GetPos();

	float distanceX = (BulletPos.GetX() - EnemyPos.GetX());
	float distanceY = (BulletPos.GetY() - EnemyPos.GetY());
	distanceY = -distanceY;
	distanceX = -distanceX;


	if (distanceX > 0)
		distanceX = 1;
	else if (distanceX < 0)
		distanceX = -1;
	
	if (distanceY > 0)
		distanceY = 1;
	else if (distanceY < 0)
		distanceY = -1;
}
*/

void Bullet::Draw(Window* window)
{
	_bulletImage->Draw(window);
}
