#pragma once

#include "moteur2d/Header_Files/Entity.h"
#include "lib2d/Header_Files/Sprite.h"

class Bullet : public Entity
{
private:
	Sprite* _bulletImage = nullptr;

	int _bulletDamage = 0;
	int _speedBullet = 500;
	int _bulletTime = 0;

	float _deltaTime = 0.f;

public:
	Bullet() {}

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;
	//void Pathfinding(Sprite* target);

	void Draw(Window* window) override;

	bool Coliding(Sprite* target);

	int GetBulletDamage() const { return _bulletDamage; }

	~Bullet() {}
};