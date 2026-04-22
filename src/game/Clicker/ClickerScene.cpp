#include "ClickerScene.h"

#include "lib2d/Header_Files/Window.h"

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
			system("cls");
			std::cout << "Shoot !\n";
			EraseEntity<SquareMob>(o);

			int skillSpawnX = rand() % 10 + 1;
			int skillSpawnY = rand() % 10 + 1;

			int skillSpawn = rand() % 3 + 1;

			++combo;

			Skill_Tree* Skill = CreateEntity<Skill_Tree>();

			switch (skillSpawn)
			{
			case 1:
				Skill->InitEntity(window, "res/game/Skill/SkillPower.png", TARGET_DELTA_TIME, Vector2f({ clicker->GetHitbox((float)skillSpawnX * 0.1f, (float)skillSpawnY * 0.1f) }));
				Skill->SetSkillNumber(1);
				break;

			case 2:
				Skill->InitEntity(window, "res/game/Skill/SkillGrow.png", TARGET_DELTA_TIME, Vector2f({ clicker->GetHitbox((float)skillSpawnX * 0.1f, (float)skillSpawnY * 0.1f) }));
				Skill->SetSkillNumber(2);
				break;

			case 3:
				Skill->InitEntity(window, "res/game/Skill/Skill_Multiplicator.png", TARGET_DELTA_TIME, Vector2f({ clicker->GetHitbox((float)skillSpawnX * 0.1f, (float)skillSpawnY * 0.1f) }));
				Skill->SetSkillNumber(3);
				break;
			}
		}
		else if (shoot)
			combo = 1;
	}

	if (clicker->GetWidth() > 32)
		clicker->ReScale(clicker->GetWidth() - 0.5f / combo, clicker->GetHeight() - 0.5f / combo);

	for (auto& o : GetEntities<Skill_Tree>())
	{
		if (GetEntity<Clicker>()->IsColliding(o) && clicker->Take())
		{
			EraseEntity<Skill_Tree>(o);

			switch (o->GetSkillNumber())
			{
			case 1:
				++attack;
				break;

			case 2:
				clicker->ReScale(clicker->GetWidth() + 10, clicker->GetHeight() + 10);
				break;

			case 3:
				attack *= 2;
				clicker->ReScale(clicker->GetWidth() * 2, clicker->GetHeight() * 2);
				break;
			}
		}
	}

	//Spawn system
	int spawnObstacle = rand() % WINDOW_HEIGHT + 720;

	if (spawnObstacle > 700)
		couldown += 10;

	int posX = rand() % WINDOW_WIDTH + 1;
	int* pPosX = &posX;

	int posY = rand() % WINDOW_HEIGHT + 1;
	int* pPosY = &posY;

	//Faire Spawn les mobs dans la partie extérieur de la fenetre pour eviter les spawn injustes
	while (posX > WINDOW_WIDTH * 7 / 8 || posX < WINDOW_WIDTH * 1 / 8)
		*pPosX = rand() % WINDOW_WIDTH + 1;

	while (posY > WINDOW_HEIGHT * 7 / 8 || posY < WINDOW_HEIGHT * 1 / 8)
		*pPosY = rand() % WINDOW_HEIGHT + 1;

	if (couldown >= spawnObstacle)
	{
		couldown = 0;
		SquareMob* mob = CreateEntity<SquareMob>();
		mob->InitEntity(window, "res/game/SqareMob.png", TARGET_DELTA_TIME, Vector2f({ (float)posX, (float)posY }));

		float size = rand() % 3 + 1;
		mob->ReScale(mob->GetWidth() * size, mob->GetHeight() * size);
	}
}
