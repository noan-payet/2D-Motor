#ifndef _H__ENDLESSRUNNER
#define _H__ENDLESSRUNNER

#include "moteur2d/Header_Files/Scene.h"

class EndlessRunnerScene : public Scene
{
private:
	int couldown = 0;

	int score;

public:
	EndlessRunnerScene();

	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__ENDLESSRUNNER