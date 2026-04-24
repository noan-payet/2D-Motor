#include "StrenghtPuzzleScene.h"

#include "game/StrenghtPuzzle/ExitLevel.h"
#include "game/StrenghtPuzzle/Movable_Object.h"
#include "game/StrenghtPuzzle/StrongMan.h"
#include "game/StrenghtPuzzle/Wall.h"

#include "lib2d/Header_Files/Window.h"

#include <fstream>
#include <string>

void StrenghtPuzzleScene::InitScene(Window* window)
{
	std::ifstream level3("res\\game\\Puzzle\\level\\level3.txt");

	if (!level3.is_open())
	{
		std::cout << "Erreur d'ouverture !\n";
		return;
	}

	std::vector<std::string> level;
	std::string line;

	while (std::getline(level3, line))
		level.push_back(line); // On ajoute la ligne au tableau

	if (DEBUG)
	{
		// Affichage pour vérifier
		for (const auto& l : level)
			std::cout << l << std::endl;
	}

	for (int row = 0; row < level.size(); ++row)
		for (int col = 0; col < level[row].size(); ++col)
			CreateEntity<Entity>()->InitEntity(window, "res\\game\\Puzzle\\Ground.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));

	for (int row = 0; row < level.size(); ++row)
	{
		for (int col = 0; col < level[row].size(); ++col)
		{
			switch (level[row][col])
			{
			case 'W':
				CreateEntity<Wall>()->InitEntity(window, "res\\game\\Puzzle\\Wall.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));
				break;

			case 'E':
				CreateEntity<ExitLevel>()->InitEntity(window, "res\\game\\Puzzle\\Exit\\exit.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f - 1, row * 17.f - 8 }));
				break;

			case 'R':
				CreateEntity<Movable_Object>()->InitEntity(window, "res\\game\\Puzzle\\Movable_Element\\Rock.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));
				break;

			case 'P':
				CreateEntity<StrongMan>()->InitEntity(window, "res\\game\\Puzzle\\Player\\player_gen_3.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));
				break;
			}
		}
	}

	GetEntity<StrongMan>()->SetPriority(-1);
}

void StrenghtPuzzleScene::UpdateScene(Window* window)
{
	StrongMan* player = GetEntity<StrongMan>();

	bool renitialize[4] = { true, true, true, true };
	player->Collision(renitialize);

	//COLLISION
	for (auto& w : GetEntities<Wall>())
	{
		if (player->IsColliding(w))
		{
			player->Collision(player->GetCollisionSide(w));
		}
	}

	for (auto& m : GetEntities<Movable_Object>())
	{
		if (player->IsColliding(m))
		{
			player->Collision(player->GetCollisionSide(m));
		}
	}

	if (player->IsColliding(GetEntity<ExitLevel>()))
	{
		std::cout << "Vous avez finit le level !\n";
		QuitScene();
	}
}
