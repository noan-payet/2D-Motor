#include "moteur2d/Header_Files/RunningGame.h"

void RunningGame::ChooseMainScene()
{
	_manager->ChooseScene();
}

void RunningGame::Init()
{
	_window.CreateOurWindow("MasterClass", WINDOW_WIDTH, WINDOW_HEIGHT);

	_manager->GetPrincipalScene()->InitScene(&_window);
	_manager->GetPrincipalScene()->BeginScene();

	_window.isOpen();
	_window.isRender();
}

void RunningGame::Loop()
{
	timer.startTimer();

	_isRunning = true;
	while (_isRunning)
	{

		timer.resetTimer();

		if (Input::getInstance().Update() == false || _manager->GetPrincipalScene()->isQuitting() == false)
		{
			_isRunning = false;
			break;
		}

		_manager->GetPrincipalScene()->UpdateAll();

		_window.clear();

		_manager->GetPrincipalScene()->UpdateScene(&_window);
		_manager->GetPrincipalScene()->Draw(&_window);

		_window.Present();

		timer.stopTimer();

		float _diff = 0.f;
		_diff = TARGET_DELTA_TIME - timer.getTimer();

		if (_diff <= 0.f)
		{
			std::this_thread::sleep_for(std::chrono::duration<double>(TARGET_DELTA_TIME));
			std::cout << "FPS : " << (int)(1 / TARGET_DELTA_TIME) << std::endl;
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::duration<double>(_diff));
			std::cout << "FPS : " << (int)(1 / _diff) << std::endl;
		}
	}

	_window.~Window();
}

void RunningGame::ChangeScene()
{
	std::cout << '\n';
	std::cout << "Est-ce que vous voulez changer de scene ? (1 = yes / 0 = no)\n";
	int choice;
	std::cin >> choice;

	if (choice == 1)
	{
		ChooseMainScene();
		Init();
		Loop();
		ChangeScene();
	}
	else if (choice < 0 || choice > 1)
	{
		std::cout << '\n';
		std::cout << "Choix invalide.\n";
		ChangeScene();
	}
}

void RunningGame::AddScenes(Scene* scene)
{
	_manager->AddScene(scene);
}

RunningGame::~RunningGame()
{
	_window.~Window();
}
