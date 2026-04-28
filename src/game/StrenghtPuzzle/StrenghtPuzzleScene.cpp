#include "StrenghtPuzzleScene.h"

#include "game/StrenghtPuzzle/ExitLevel.h"
#include "game/StrenghtPuzzle/Movable_Object.h"
#include "game/StrenghtPuzzle/StrongMan.h"
#include "game/StrenghtPuzzle/Wall.h"

#include "lib2d/Header_Files/Window.h"
#include "lib2d/Header_Files/Input.h"

#include <fstream>
#include <string>

void StrenghtPuzzleScene::InitScene(Window* window)
{
	levelPath = {
		"res\\game\\Puzzle\\level\\level1.txt",
		"res\\game\\Puzzle\\level\\level2.txt",
		"res\\game\\Puzzle\\level\\level3.txt"
	};

	std::ifstream levels(levelPath[levelIndex]);

	if (!levels.is_open())
	{
		std::cout << "Erreur d'ouverture !\n";
		return;
	}

	std::vector<std::string> level;
	std::string line;

	while (std::getline(levels, line))
		level.push_back(line); // On ajoute la ligne au tableau

	levels.close();

	if (DEBUG)
	{
		// Affichage pour vérifier
		for (const auto& l : level)
			std::cout << l << std::endl;
	}

	float scale = 5.f;

	for (int row = 0; row < level.size(); ++row)
		for (int col = 0; col < level[row].size(); ++col)
		{
			Vector2f spawn = Vector2f({ col * 17.f * scale, row * 17.f * scale });

			CreateEntity<Entity>()->InitEntity(window, "res\\game\\Puzzle\\Ground.png", TARGET_DELTA_TIME, spawn);

			if (level[row][col] != 'W')
			{
				Entity* teleport = CreateEntity<Entity>();
				teleport->InitEntity(window, "", TARGET_DELTA_TIME, spawn);

				teleport->ReScale(4.f, 4.f);

				Vector2f dSpawn = spawn.operator+({ 17.f, 17.f });

				teleport->SetHitbox({ 
					dSpawn.GetX() + 4,
					dSpawn.GetY()}
					);

				teleport->SetType("Teleport");
				teleport->SetPriority(-1);

				//teleport->SetDebug(true);
			}
		}

	StrongMan* player = nullptr;

	for (int row = 0; row < level.size(); ++row)
	{
		for (int col = 0; col < level[row].size(); ++col)
		{
			Movable_Object* movable = nullptr;
			Vector2f spawn = Vector2f({ col * 17.f * scale, row * 17.f * scale });

			switch (level[row][col])
			{
			case 'W':
				CreateEntity<Wall>()->InitEntity(window, "res\\game\\Puzzle\\Wall.png", TARGET_DELTA_TIME, spawn);
				break;

			case 'E':
				CreateEntity<ExitLevel>()->InitEntity(window, "res\\game\\Puzzle\\Exit\\exit.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f * scale - 1 * scale, row * 17.f * scale - 8 * scale }));
				break;

			case 'R':
				movable = CreateEntity<Movable_Object>();
				movable->InitEntity(window, "res\\game\\Puzzle\\Movable_Element\\Rock.png", TARGET_DELTA_TIME, spawn);
				//movable->SetDebug(true);
				break;

			case 'P':
				CreateEntity<StrongMan>()->InitEntity(window, "res\\game\\Puzzle\\Player\\player_gen_3.png", TARGET_DELTA_TIME, spawn);
				player = GetEntity<StrongMan>();
				break;
			}
		}
	}

	ReScaleAllEntity(scale);

	player->SetHeigher(player->GetHeight() / 2);
	player->SetWighter(player->GetWidth() / 3);
	//player->SetDebug(true);

	for (auto& m : GetEntities<Movable_Object>())
	{
		m->SetWighter(4);
		m->SetHeigher(4);
	}

	GetEntity<StrongMan>()->SetPriority(-1);
}

void StrenghtPuzzleScene::UpdateScene(Window* window)
{
	StrongMan* player = GetEntity<StrongMan>();

	std::vector<bool> renitialize = { true, true, true, true };
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
		Vector2f restPos = m->GetPos();

		if (player->IsColliding(m))
		{
			player->Collision(player->GetCollisionSide(m));

			if (player->Push())
			{
				int sideY = m->GetCollisionSide(player)[1] - m->GetCollisionSide(player)[0];
				int sideX = m->GetCollisionSide(player)[3] - m->GetCollisionSide(player)[2];

				m->SetHitbox({
					m->GetPos().GetX() + sideX * 17.f,
					m->GetPos().GetY() + sideY * 17.f },
					0.f, 0.f);
			}
		}

		Movable_Object* lastCollidingMovable = m;

		for (auto& w : GetEntities<Wall>())
		{
			if (m->IsColliding(w) && m->IsColliding(w))
			{
				m->SetHitbox(restPos, 0.f, 0.f);
				break;
			}
		}

		for (auto& w : GetEntities<Movable_Object>())
		{
			if (m != w && m->IsColliding(w))
			{
				m->SetHitbox(restPos, 0.f, 0.f);
				break;
			}
		}
	}

	/*for (auto& e : GetEntities<Entity>())
	{
		if (player->IsColliding(e) && e->GetType() == "Teleport")
		{
			player->SetHitbox(e->GetPos());
		}
	}*/

	for (auto& e : GetEntities<Entity>())
	{
		if (player->IsColliding(e) && e->GetType() == "Teleport" && player->IsColliding(GetEntity<ExitLevel>()))
		{
			std::cout << "\nVous avez finit le level !\n";
			EraseAllEntities();
			++levelIndex;

			if (levelIndex >= levelPath.size())
			{
				std::cout << "\n Vous avez finit tous les levels !\n";
				std::cout << " Vous avez besoin de " << reset << " resets !\n";
				levelIndex = 0;
				QuitScene();
				return;
			}

			InitScene(window);
		}
	}

	Input& input = Input::getInstance();
	if (input.isKeyHeld(SDLK_BACKSPACE))
	{
		std::cout << "\nVous avez renitialiser le level !\n";
		++reset;
		EraseAllEntities();
		InitScene(window);
	}
}
