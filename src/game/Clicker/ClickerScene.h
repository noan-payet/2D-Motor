#ifndef _H__CLICKERSCENE
#define _H__CLICKERSCENE

#include "moteur2d/Header_Files/Scene.h"

class ClickerScene : public Scene
{
private:
	int score = 0;

	int couldown = 0;
	int alpha = 0;
	int attack = 1;

	int combo = 0;
	int highestCombo = 0;

	int multiplicator = 0;
	int highestMultiplicator = 0;
	float multiCombo = 1.f;

	float transparenceCouldown = 0.f;
	float spawnCouldown = 0.f;

public:
	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__CLICKERSCENE