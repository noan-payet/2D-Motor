#pragma once
#include "lib2d/Header_Files/Sprite.h"
#include "moteur2d/Header_Files/Entity.h"
#include <vector>

class MapManager : public Entity
{
private:
	struct Parallax
	{
		Sprite image;
		float currentX = 0.f;
	};

	std::vector<Parallax> layers;
	std::vector<Parallax> reflects;
	std::vector<Parallax> backs; 

	int backAcceleration = 0;
	float backSpeed = 0.f;

	int reflectAcceleration = 0;
	float reflectSpeed = 200.f * 2;

	int layersAcceleration = 0;
	float layersSpeed = 50.f * 2;

public:
	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;
	void Update() override;
	void Draw(Window* window) override;
};