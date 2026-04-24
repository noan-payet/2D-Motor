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

	float speed = 150.f;

	bool direction[4] = { true, true, true, true }; // up, down, left, right

	std::vector<std::vector<int>> paths;

	std::vector<std::vector<bool>> mazeGrid; // true for wall, false for path

public:
	void GenerateMaze(int width, int height);
	void Collision(int number, bool b); // 0 = no collision, 1 = up, 2 = down, 3 = left, 4 = right
};

#endif // !_H__MAZE_GENERATOR