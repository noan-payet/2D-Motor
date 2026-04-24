#ifndef _H__MAZESCENE
#define _H__MAZESCENE

#include "moteur2d/Header_Files/Scene.h"

class MazeScene : public Scene
{
private:
	int second = 0;
	int secondBefore = 0;

public:
	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__MAZESCENE