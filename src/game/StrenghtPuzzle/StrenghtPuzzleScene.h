#ifndef _H__PUZZLESCENE
#define _H__PUZZLESCENE

#include "moteur2d/Header_Files/Scene.h"

class StrenghtPuzzleScene : public Scene
{
public:
	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;

private:
	bool DEBUG = false;

	std::vector<std::string> levelPath;
	int levelIndex = 0;

	int reset = 0;
};

#endif // !_H__PUZZLESCENE