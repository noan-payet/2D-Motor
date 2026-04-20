#include "moteur2d/Header_Files/SceneManager.h"

void SceneManager::AddScene(Scene* scene)
{
	sceneList.push_back(scene);
}

void SceneManager::ChooseScene()
{
	std::cout << "Pour commencer, voici les scenes disponibles : \n\n";

	std::cout << "1 : Shoot'em up\n";
	std::cout << "Ceci est un prototype et vous ne pouvez que vous deplacer et tirer des projectiles.\n";
	std::cout << "Pour vous deplacer, utilisez les touches ZQSD ou les fleches directionnelles.\n";
	std::cout << "Pour tirer, utilisez la touche ESPACE.\n\n";

	std::cout << "2 : Ball Rebondissante\n";
	std::cout << "Dans cette scene, des balle rebondissent sur les bords de la fenetre.\n";
	std::cout << "Pour rajouter une balle, appuyez sur la touche B.\n\n";

	std::cout << "3 : EndlessRunner\n";

	std::cout << "Choisis une scene a jouer : (1-3)\n";
	int choice;
	std::cin >> choice;

	while (choice < 1 || choice > (int)sceneList.size())
	{
		std::cout << '\n';
		std::cout << "Choix invalide. Choisis une scene a jouer : (1-" << sceneList.size() << ")\n";
		std::cin >> choice;
	}

	_principalScene = sceneList[choice - 1];
}

Scene* SceneManager::GetPrincipalScene()
{
	return _principalScene;
}
