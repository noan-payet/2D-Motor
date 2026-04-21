#include <iostream>
#include "main.h"

#include "game/SceneBall.h"
#include "game/ScenePong.h"
#include "game/EndlessRunner/EndlessRunnerScene.h"
#include "game/Dodger/DodgerScene.h"

int main()
{
    std::cout << "Salut ! Bienvenue dans mon premier moteur de jeu 2D en C++ !\n\n";

    RunningGame gameManager;

    Shoot_them_up* shoot = new Shoot_them_up(TARGET_DELTA_TIME);
    SceneBall* sceneball = new SceneBall();
	EndlessRunnerScene* endlessRunnerScene = new EndlessRunnerScene();
	DodgerScene* dodgerScene = new DodgerScene();

    gameManager.AddScenes(shoot);
    gameManager.AddScenes(sceneball);
	gameManager.AddScenes(endlessRunnerScene);
	gameManager.AddScenes(dodgerScene);

	gameManager.ChooseMainScene();

    gameManager.Init();
    gameManager.Loop();
	gameManager.ChangeScene();

    return 0;
}