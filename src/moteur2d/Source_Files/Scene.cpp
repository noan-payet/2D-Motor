#include "Header_Files/Scene.h"
#include "lib2d/Header_Files/Window.h"

void Scene::Draw(Window* window)
{
	for (auto& e : entityList)
	{
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
