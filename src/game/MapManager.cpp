#include "MapManager.h"
#include "lib2d/Header_Files/Window.h"

void MapManager::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	Sprite Sky = {   "res\\game\\Background\\skycolor.png", pos };
	Sprite Moon = {  "res\\game\\Background\\moon.png", pos };
	Sprite Water = { "res\\game\\Background\\watercolor.png", pos };
	Sprite Hill = {  "res\\game\\Background\\backhill.png", pos };

	Sprite ReflectCloud = {       "res\\game\\Midground\\reflectcloud.png", pos };
	Sprite ReflectEiffeiTower = { "res\\game\\Midground\\reflecteiffeltower.png", pos };
	Sprite ReflectBuilding = {    "res\\game\\Midground\\reflectbuilding.png", pos };
	Sprite ReflectRiverBank = {   "res\\game\\Midground\\reflectriverbank.png", pos };

	Sprite BackBuilding3 = { "res\\game\\Foreground\\backbuilding3.png", pos };
	Sprite BackBuilding2 = { "res\\game\\Foreground\\backbuilding2.png", pos };
	Sprite BackBuilding1 = { "res\\game\\Foreground\\backbuilding1.png", pos };
	Sprite Cloud = {         "res\\game\\Foreground\\skycloud.png", pos };
	Sprite EifelTower = {    "res\\game\\Foreground\\eifeltower.png", pos };
	Sprite Building = {      "res\\game\\Foreground\\riversidebuilding.png", pos };
	Sprite People = {        "res\\game\\Foreground\\riverbankwithpeople.png", pos };
	Sprite Barge = {         "res\\game\\Foreground\\barge river.png", pos };
	Sprite Forest = {        "res\\game\\Foreground\\frontforest.png", pos };

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