#ifndef _H__DODGERSCENE
#define _H__DODGERSCENE

#include "moteur2d/Header_Files/Scene.h"

class DodgerScene : public Scene
{
public:
	DodgerScene() {};

	void InitScene(Window* window) override;

	void UpdateScene(Window* window) override;
};

#endif // !_H__DODGERSCENE