#include <iostream>
#include "main.h"

int main()
{
    std::cout << "Salut ! Bienvenue dans mon premier moteur de jeu 2D en C++ !\n\n";

    RunningGame gameManager;

    Shoot_them_up* shoot = new Shoot_them_up(TARGET_DELTA_TIME);
    SceneBall* sceneball = new SceneBall();

    gameManager.AddScenes(shoot);
    gameManager.AddScenes(sceneball);

    gameManager.Init();
    gameManager.Loop();
	gameManager.ChangeScene();

    return 0;
}