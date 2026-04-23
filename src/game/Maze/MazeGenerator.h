#ifndef _H__MAZE_GENERATOR
#define _H__MAZE_GENERATOR

#include "moteur2d/Header_Files/Entity.h"

class MazeGenerator : public Entity
{
private:
	float _deltaTime = 0.f;

public:
	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;
};

#endif // !_H__MAZE_GENERATOR