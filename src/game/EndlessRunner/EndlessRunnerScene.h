#ifndef _H__ENDLESSRUNNER
#define _H__ENDLESSRUNNER

#include "moteur2d/Header_Files/Scene.h"

class Runner;

class EndlessRunnerScene : public Scene
{
private:
	Runner* _runner = nullptr;

public:
	EndlessRunnerScene();

	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__ENDLESSRUNNER