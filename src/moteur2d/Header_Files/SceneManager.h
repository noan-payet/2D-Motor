#ifndef SCENEMANAGER
#define SCENEMANAGER

#include "moteur2d/Header_Files/Scene.h"
#include <vector>

class SceneManager
{
private:
	std::vector<class Scene*> sceneList;
	Scene* _principalScene = nullptr;

public:
	SceneManager() {}

	void AddScene(Scene* scene);
	void ChooseScene();
	Scene* GetPrincipalScene();

};

#endif // !SCENEMANAGER