#include "MapManager.h"
#include "lib2d/Header_Files/Window.h"

void MapManager::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	Sprite Sky = {   pos, "res\\game\\Background\\skycolor.png" };
	Sprite Moon = {  pos, "res\\game\\Background\\moon.png" };
	Sprite Water = { pos, "res\\game\\Background\\watercolor.png" };
	Sprite Hill = {  pos, "res\\game\\Background\\backhill.png" };

	Sprite ReflectCloud = {       pos, "res\\game\\Midground\\reflectcloud.png" };
	Sprite ReflectEiffeiTower = { pos, "res\\game\\Midground\\reflecteiffeltower.png" };
	Sprite ReflectBuilding = {    pos, "res\\game\\Midground\\reflectbuilding.png" };
	Sprite ReflectRiverBank = {   pos, "res\\game\\Midground\\reflectriverbank.png" };

	Sprite BackBuilding3 = { pos, "res\\game\\Foreground\\backbuilding3.png" };
	Sprite BackBuilding2 = { pos, "res\\game\\Foreground\\backbuilding2.png" };
	Sprite BackBuilding1 = { pos, "res\\game\\Foreground\\backbuilding1.png" };
	Sprite Cloud = {         pos, "res\\game\\Foreground\\skycloud.png" };
	Sprite EifelTower = {    pos, "res\\game\\Foreground\\eifeltower.png" };
	Sprite Building = {      pos, "res\\game\\Foreground\\riversidebuilding.png" };
	Sprite People = {        pos, "res\\game\\Foreground\\riverbankwithpeople.png" };
	Sprite Barge = {         pos, "res\\game\\Foreground\\barge river.png" };
	Sprite Forest = {        pos, "res\\game\\Foreground\\frontforest.png" };

	backs.emplace_back(Sky); backs.emplace_back(Moon);
	backs.emplace_back(Water); backs.emplace_back(Hill);

	reflects.emplace_back(ReflectCloud); reflects.emplace_back(ReflectEiffeiTower);
	reflects.emplace_back(ReflectBuilding); reflects.emplace_back(ReflectRiverBank);

	layers.emplace_back(BackBuilding3); layers.emplace_back(BackBuilding2); layers.emplace_back(BackBuilding1);
	layers.emplace_back(Cloud); layers.emplace_back(EifelTower); layers.emplace_back(Building); layers.emplace_back(People);
	layers.emplace_back(Barge); layers.emplace_back(Forest);

	for (auto& background : backs) {
		background.image.loadSprite(window);
		background.image.Resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	for (auto& layer : layers) {
		layer.image.loadSprite(window);
		layer.image.Resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	for (auto& reflect : reflects) {
		reflect.image.loadSprite(window);
		reflect.image.Resize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
}

void MapManager::Update()
{
	backAcceleration = 0;
	backSpeed = 0.f;

	// Scroll the background
	for (auto& background : backs) {
		background.currentX -= backSpeed * TARGET_DELTA_TIME;
		if (background.currentX <= -WINDOW_WIDTH) {
			background.currentX = 0.0f;
		}

		// On dessine le premier niveau
		background.image.SetPos({ background.currentX, 0 });
		backSpeed += backAcceleration + 10;
	}

	reflectAcceleration = 0;
	reflectSpeed = 200.f * 2;

	for (auto& reflect : reflects) {
		reflect.currentX -= reflectSpeed * TARGET_DELTA_TIME;
		if (reflect.currentX <= -WINDOW_WIDTH) {
			reflect.currentX = 0.0f;
		}

		// On dessine le premier niveau
		reflect.image.SetPos({ reflect.currentX, 0.f });
		reflectSpeed += reflectAcceleration + 50 * 2;
	}

	layersAcceleration = 0;
	layersSpeed = 50.f * 2;

	for (auto& layer : layers) {
		layer.currentX -= layersSpeed * TARGET_DELTA_TIME;
		if (layer.currentX <= -WINDOW_WIDTH) {
			layer.currentX = 0.0f;
		}

		// On dessine le premier niveau
		layer.image.SetPos({ layer.currentX, 0 });

		layersSpeed += layersAcceleration + 50 * 2;
	}
}

void MapManager::Draw(Window* window)
{
	for (auto& background : backs) {
		background.image.Draw(window);

		// On dessine le premier niveau a l'infini
		background.image.SetPos({ background.currentX + WINDOW_WIDTH, 0 });

		background.image.Draw(window);
	}

	for (auto& reflect : reflects) {
		reflect.image.Draw(window);

		// On dessine le premier niveau a l'infini
		reflect.image.SetPos({ reflect.currentX + WINDOW_WIDTH, 0 });

		reflect.image.Draw(window);
	}

	for (auto& layer : layers) {
		layer.image.Draw(window);

		// On dessine le premier niveau a l'infini
		layer.image.SetPos({ layer.currentX + WINDOW_WIDTH, 0 });

		layer.image.Draw(window);
	}
}