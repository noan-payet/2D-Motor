#include "ClickerScene.h"

#include "lib2d/Header_Files/Window.h"
#include "lib2d/Header_Files/Input.h"

#include "game/Clicker/Clicker.h"
#include "game/Dodger/SquareMob.h"
#include "game/Clicker/Skill_Tree.h"

void ClickerScene::InitScene(Window* window)
{
	CreateEntity<Clicker>()->InitEntity(window, "res/game/camera.png", TARGET_DELTA_TIME, Vector2f({ 640.f, 360.f }));
	Clicker* clicker = GetEntity<Clicker>();
	clicker->SetPriority(-1);
	alpha = clicker->GetSprite()->GetAlpha();
}

void ClickerScene::UpdateScene(Window* window)
{
	if (combo > highestCombo)
		highestCombo = combo;

	if (multiplicator > highestMultiplicator)
		highestMultiplicator = multiplicator;

	Clicker* clicker = GetEntity<Clicker>();

	if (transparenceCouldown > 0.f)
	{
		clicker->GetSprite()->SetAlpha(alpha + alpha * transparenceCouldown);
		transparenceCouldown -= 0.01f;
	}
	else
		transparenceCouldown = 0.f;

	bool shoot = false;

	if (clicker->Shoot() && transparenceCouldown == 0.f)
	{
		transparenceCouldown = 1.f;
		shoot = true;
	}

	// Collision
	for (auto& o : GetEntities<SquareMob>())
	{
		if (GetEntity<Clicker>()->IsColliding(o) && shoot)
		{
			std::cout << "Shoot !\n";

			o->LoseLife(attack);
		}
		else if (shoot)
			combo = 1;
	}

	//Update entities
	for (auto& o : GetEntities<SquareMob>())
	{
		if (o->GetLife() <= 0)
		{
			EraseEntity<SquareMob>(o);

			++combo;
			multiplicator = 1 * (int)multiCombo;
			score += 10 * multiplicator;
		}
		else
			o->SetLife(o->GetLife() + 0.001f);
	}

	if (multiCombo > 2.f)
		multiCombo -= 0.001f;
	else if (multiCombo > 1.f)
		multiCombo = 2.f;

	//std::cout << "MultiCombo : " << multiCombo << "\n";

	if (clicker->GetWidth() > 32)
		clicker->ReScale(clicker->GetWidth() - 0.2f / combo, clicker->GetHeight() - 0.2f / combo);

	for (auto& o : GetEntities<Skill_Tree>())
	{
		switch (o->GetSkillNumber())
		{
		case 1:
			++attack;
			break;

		case 2:
			if (clicker->GetWidth() * 1.5f < 720)
				clicker->ReScale(clicker->GetWidth() * 1.5f, clicker->GetHeight() * 1.5f);
			else
				clicker->ReScale(720, 720);

			break;

		case 3:
			multiCombo += 1.f;
			break;
		}

		o->SetSkillNumber(0);

		o->GetSprite()->SetAlpha(o->GetSprite()->GetAlpha() - 5.f);
		o->SetHitbox({ o->GetPos().GetX(), o->GetPos().GetY() - 1.f }, 0.f, 0.f);

		if (o->GetSprite()->GetAlpha() <= 0)
			EraseEntity<Skill_Tree>(o);
	}

	// Show information in console
	std::cout << 
		"Score : " << score << 
		"\nCombo : " << combo << 
		"\nMultiplicator : " << multiplicator <<
		"\n";

	//Spawn system
	if (spawnCouldown > 0.f)
		spawnCouldown -= 0.1f;

	if (multiplicator > 0 && spawnCouldown <= 0.f)
	{
		spawnCouldown = 1.f / multiplicator;

		multiplicator--;

		Skill_Tree* Skill = CreateEntity<Skill_Tree>();
		std::string path;

		int skillSpawnX = rand() % 10 + 1;
		int skillSpawnY = rand() % 10 + 1;

		int skillSpawn = rand() % 3 + 1;

		switch (skillSpawn)
		{
		case 1:
			path = "res/game/Skill/SkillPower.png";
			break;

		case 2:
			path = "res/game/Skill/SkillGrow.png";
			break;

		case 3:
			path = "res/game/Skill/Skill_Multiplicator.png";
			break;
		}

		Skill->InitEntity(
			window,
			path,
			TARGET_DELTA_TIME,
			Vector2f({ WINDOW_WIDTH - 100, 100 })
		);

		Skill->SetSkillNumber(skillSpawn);
	}

	int spawnObstacle = rand() % WINDOW_HEIGHT + 720;

	if (spawnObstacle > 700)
		couldown += 10;

	int posX = rand() % WINDOW_WIDTH + 1;
	int* pPosX = &posX;

	int posY = rand() % WINDOW_HEIGHT + 1;
	int* pPosY = &posY;

	if (couldown >= spawnObstacle)
	{
		couldown = 0;
		SquareMob* mob = CreateEntity<SquareMob>();
		mob->InitEntity(window, "res/game/SqareMob.png", TARGET_DELTA_TIME, Vector2f({ (float)posX, (float)posY }));

		float size = rand() % 3 + 1;
		mob->ReScale(mob->GetWidth() * size, mob->GetHeight() * size);
	}

	//Quit game
	if (Input::getInstance().isKeyHeld(SDLK_ESCAPE))
	{
		std::cout <<
			"\n Score : " << score <<
			"\n Highest Combo : " << highestCombo <<
			"\n Highest Multiplicator : " << highestMultiplicator <<
			"\n";

		QuitScene();
	}
}
