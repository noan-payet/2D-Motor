#ifndef _H__MAZE_GENERATOR
#define _H__MAZE_GENERATOR

#include "moteur2d/Header_Files/Entity.h"
#include <vector>

class MazeGenerator : public Entity
{
private:
	float _deltaTime = 0.f;

public:
	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;

private:
	int mazeWidth = 0, mazeHeight = 0;
	int lineSize = 0;
	std::vector<std::vector<int>> paths;

	std::vector<std::vector<bool>> mazeGrid; // true for wall, false for path

	Sprite* _spriteResolve = nullptr;

public:
	void GenerateMaze(int width, int height);
};

#endif // !_H__MAZE_GENERATOR