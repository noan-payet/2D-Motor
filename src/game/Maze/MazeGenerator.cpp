#include "MazeGenerator.h"

void MazeGenerator::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_sprite = new Sprite(GetPos());
	_spriteResolve = new Sprite(Vector2f({ GetPos().GetX() + 70.f, GetPos().GetY() + 70.f}));

	width = _sprite->GetWidth();
	height = _sprite->GetHeight();

	_deltaTime = deltaTime;
}

void MazeGenerator::Update()
{
}

void MazeGenerator::Draw(Window* window)
{
	Vector2f startWall;
	Vector2f endWall;

	Vector2f startPath;
	Vector2f endPath;

	// Draw the paths based on the mazeGrid
	for (int row = 0; row < mazeHeight - 1; ++row) {
		for (int col = 0; col < mazeWidth - 1; ++col) {
			
			// Draw hoizontal line
			startPath = { _spriteResolve->GetPos().GetX() + col * 140.f, _spriteResolve->GetPos().GetY() + row * 140.f };
			endPath = { startPath.GetX() + 140.f, startPath.GetY() };

			_spriteResolve->DrawLine(window, startPath, endPath);

			// Draw vertical line
			startPath = { _spriteResolve->GetPos().GetX() + col * 140.f, _spriteResolve->GetPos().GetY() + row * 140.f };
			endPath = { startPath.GetX(), startPath.GetY() + 140.f };

			_spriteResolve->DrawLine(window, startPath, endPath);
		}
	}

	// Draw last horizontal line
	for (int col = 0; col < mazeWidth - 1; ++col) {
		startPath = { _spriteResolve->GetPos().GetX() + col * 140.f, _spriteResolve->GetPos().GetY() + (mazeHeight - 1) * 140.f };
		endPath = { startPath.GetX() + 140.f, startPath.GetY() };

		_spriteResolve->DrawLine(window, startPath, endPath);
	}

	// Draw last vertical line
	for (int row = 0; row < mazeHeight - 1; ++row) {
		startPath = { _spriteResolve->GetPos().GetX() + (mazeWidth - 1) * 140.f, _spriteResolve->GetPos().GetY() + row * 140.f };
		endPath = { startPath.GetX(), startPath.GetY() + 140.f };

		_spriteResolve->DrawLine(window, startPath, endPath);
	}

	// Draw the maze based on the mazeGrid
	for (int row = 0; row < mazeHeight; ++row) {
		for (int col = 0; col < mazeWidth; ++col) {

			if (mazeGrid[row][col] == true)
			{
				// Draw hoizontal line
				startWall = { GetPos().GetX() + col * 140.f, GetPos().GetY() + row * 140.f };
				endWall = { startWall.GetX() + 140.f, startWall.GetY() };

				_sprite->DrawLine(window, startWall, endWall);

				// Draw vertical line
				startWall = { GetPos().GetX() + col * 140.f, GetPos().GetY() + row * 140.f };
				endWall = { startWall.GetX(), startWall.GetY() + 140.f };

				_sprite->DrawLine(window, startWall, endWall);
			}
		}
	}

	if (mazeGrid[mazeHeight - 1][mazeWidth - 1] == true)
	{
		// Draw last horizontal line
		for (int col = 0; col < mazeWidth; ++col) {
			startWall = { GetPos().GetX() + col * 140.f, GetPos().GetY() + mazeHeight * 140.f };
			endWall = { startWall.GetX() + 140.f, startWall.GetY() };

			_sprite->DrawLine(window, startWall, endWall);
		}

		// Draw last vertical line
		for (int row = 0; row < mazeHeight; ++row) {
			startWall = { GetPos().GetX() + mazeWidth * 140.f, GetPos().GetY() + row * 140.f };
			endWall = { startWall.GetX(), startWall.GetY() + 140.f };

			_sprite->DrawLine(window, startWall, endWall);
		}
	}
}

void MazeGenerator::GenerateMaze(int width, int height)
{
	mazeWidth = width;
	mazeHeight = height;

	mazeGrid.resize(mazeHeight, std::vector<bool>(mazeWidth, true)); // Initialize all cells as walls
}
