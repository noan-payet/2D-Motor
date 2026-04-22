#ifndef _H__CLICKERSCENE
#define _H__CLICKERSCENE

#include "moteur2d/Header_Files/Scene.h"

class ClickerScene : public Scene
{
private:
	int couldown = 0;
	int alpha = 0;

	float transparenceCouldown = 0.f;

public:
	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__CLICKERSCENE