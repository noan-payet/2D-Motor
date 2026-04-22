#ifndef RUN
#define RUN

#define TARGET_FPS 60
#define TARGET_DELTA_TIME 1.f / TARGET_FPS

#include "moteur2d/Header_Files/SceneManager.h"
#include "moteur2d/Header_Files/Timer.h"

#include "lib2d/Header_Files/Window.h"
#include "lib2d/Header_Files/Input.h"

#include <thread>

class RunningGame
{
private:
	Window _window;
	SceneManager*  _manager = new SceneManager();

	Timer timer;

	bool _isRunning = true;
	bool showFPS = false;

public:
	RunningGame():
	_manager(new SceneManager()){}

	void ChooseMainScene();

	void Init();
	void Loop();
	void ChangeScene();

	void AddScenes(Scene* scene);

	~RunningGame();
};

#endif // !RUN