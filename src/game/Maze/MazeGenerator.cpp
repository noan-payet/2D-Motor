#include "MazeGenerator.h"

#include "lib2d/Header_Files/Input.h"

void MazeGenerator::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos());

	_width = _sprite->GetWidth();
	_height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void MazeGenerator::Update()
{
	Input& input = Input::getInstance();

	float speed = 100.f;

	if (input.isKeyHeld(SDLK_Z)) {
		SetPos({ GetPos().GetX(), GetPos().GetY() + speed * _deltaTime });
	}
	else if (input.isKeyHeld(SDLK_S)) {
		SetPos({ GetPos().GetX(), GetPos().GetY() - speed * _deltaTime });
	}
	else if (input.isKeyHeld(SDLK_Q)) {
		SetPos({ GetPos().GetX() + speed * _deltaTime, GetPos().GetY() });
	}
	else if (input.isKeyHeld(SDLK_D)) {
		SetPos({ GetPos().GetX() - speed * _deltaTime, GetPos().GetY() });
	}
}

void MazeGenerator::Draw(Window* window)
{

	Vector2f startPath;
	Vector2f endPath;

	// Draw the paths based on the mazeGrid
	for (int row = 0; row < mazeHeight - 1; ++row) {
		for (int col = 0; col < mazeWidth - 1; ++col) {
			
			switch (paths[row][col])
			{
			case 1:
				// Draw hoizontal line
				startPath = { GetPos().GetX() + col * lineSize, GetPos().GetY() + row * lineSize };
				endPath = { startPath.GetX() + lineSize, startPath.GetY() };

				_sprite->DrawLine(window, startPath, endPath);
				break;

			case 2:
				// Draw vertical line
				startPath = { GetPos().GetX() + col * lineSize, GetPos().GetY() + row * lineSize };
				endPath = { startPath.GetX(), startPath.GetY() + lineSize };

				_sprite->DrawLine(window, startPath, endPath);
				break;
			}
		}
	}
}

void MazeGenerator::GenerateMaze(int width, int height)
{
	mazeWidth = width;
	mazeHeight = height;

	lineSize = 140.f;

	_width = width * lineSize;
	_height = height * lineSize;

	mazeGrid.resize(mazeHeight, std::vector<bool>(mazeWidth, true)); // Initialize all cells as walls
	paths.resize(mazeHeight, std::vector<int>(mazeWidth, 0)); // Initialize paths

	for (int row = 0; row < mazeHeight - 1; ++row) {
		for (int col = 0; col < mazeWidth - 1; ++col) {

			int pathType = rand() % 2 + 1; // Randomly choose between horizontal (1) and vertical (2) path
			paths[row][col] = pathType;

			if (pathType == 1) {
				// Create horizontal path
				mazeGrid[row][col] = false;
				mazeGrid[row][col + 1] = false;
			}
			else {
				// Create vertical path
				mazeGrid[row][col] = false;
				mazeGrid[row + 1][col] = false;
			}
		}
	}
}