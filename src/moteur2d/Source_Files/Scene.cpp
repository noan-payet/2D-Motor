#include "Header_Files/Scene.h"
#include "lib2d/Header_Files/Window.h"

void Scene::Draw(Window* window)
{
	if (entityList.size() == 0)
		return;

	for (auto& e : entityList)
	{
		if (e->GetPriority() != -1)
			e->Draw(window);
	}

	for (auto& e : entityList)
	{
		if (e->GetPriority() == -1)
			e->Draw(window);
	}
}

void Scene::UpdateAll()
{
	for (auto& e : entityList)
	{
		e->Update();
	}
}
