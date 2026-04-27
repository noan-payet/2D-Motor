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

	std::ifstream level3(levelPath[levelIndex]);

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
		{
			CreateEntity<Entity>()->InitEntity(window, "res\\game\\Puzzle\\Ground.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));

			if (level[row][col] != 'W')
			{
				Entity* teleport = CreateEntity<Entity>();
				teleport->InitEntity(window, "", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));

				teleport->SetWidth(4.f);
				teleport->SetHeight(4.f);

				teleport->SetHitbox(Vector2f({ col * 17.f + 8.5f, row * 17.f + 8.5f }));

				teleport->SetType("Teleport");
				teleport->SetPriority(-1);
			}
		}

	for (int row = 0; row < level.size(); ++row)
	{
		for (int col = 0; col < level[row].size(); ++col)
		{
			Movable_Object* movable = nullptr;

			switch (level[row][col])
			{
			case 'W':
				CreateEntity<Wall>()->InitEntity(window, "res\\game\\Puzzle\\Wall.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));
				break;

			case 'E':
				CreateEntity<ExitLevel>()->InitEntity(window, "res\\game\\Puzzle\\Exit\\exit.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f - 1, row * 17.f - 8 }));
				break;

			case 'R':
				movable = CreateEntity<Movable_Object>();
				movable->InitEntity(window, "res\\game\\Puzzle\\Movable_Element\\Rock.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));
				break;

			case 'P':
				CreateEntity<StrongMan>()->InitEntity(window, "res\\game\\Puzzle\\Player\\player_gen_3.png", TARGET_DELTA_TIME, Vector2f({ col * 17.f, row * 17.f }));
				GetEntity<StrongMan>()->SetHeigher(10.5f);
				GetEntity<StrongMan>()->SetWighter(10.5f);
				break;
			}
		}
	}

	/*for (auto& a : GetEntities<Entity>())
	{
		a->ReScale(a->GetWidth() * 2, a->GetHeight() * 2);
		a->SetPos(Vector2f({ a->GetPos().GetX() * 2, a->GetPos().GetY() * 2 }));
	}*/

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

			int sideY = m->GetCollisionSide(player)[1] - m->GetCollisionSide(player)[0];
			int sideX = m->GetCollisionSide(player)[3] - m->GetCollisionSide(player)[2];

			m->SetHitbox({
				m->GetPos().GetX() + sideX * 17.f,
				m->GetPos().GetY() + sideY * 17.f }, 
				0.f, 0.f);
		}

		Movable_Object* lastCollidingMovable = m;

		for (auto& w : GetEntities<Wall>())
		{
			if (m->IsColliding(w) && m->GetPos().GetX() == w->GetPos().GetX() && m->GetPos().GetY() == w->GetPos().GetY())
			{
				m->SetHitbox(restPos, 0.f, 0.f);
				break;
			}
		}

		for (auto& w : GetEntities<Movable_Object>())
		{
			if (m != w && m->GetPos().GetX() == w->GetPos().GetX() && m->GetPos().GetY() == w->GetPos().GetY())
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
			std::cout << "Vous avez finit le level !\n";
			EraseAllEntities();
			++levelIndex;

			if (levelIndex >= levelPath.size())
			{
				std::cout << "Vous avez finit tous les levels !\n";
				QuitScene();
				return;
			}

			InitScene(window);
		}
	}

	Input& input = Input::getInstance();
	if (input.isKeyHeld(SDLK_BACKSPACE))
	{
		std::cout << "Vous avez réinitialisé le level !\n";
		EraseAllEntities();
		InitScene(window);
	}
}
