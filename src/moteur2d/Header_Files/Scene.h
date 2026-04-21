#ifndef SCENE
#define SCENE

#include "lib2d/Header_Files/Drawable.h"
#include "lib2d/Header_Files/Input.h"
#include "moteur2d/Header_Files/Entity.h"
#include <vector>

class Scene : public Drawable
{
private:
	std::vector<class Entity*> entityList;
	bool _isRunning = true;

public:
	Scene() {}

	virtual void InitScene(Window* window) {}

	void Draw(Window* window) override;

	void UpdateAll();
	virtual void UpdateScene(Window* window) {}

	void BeginScene() { _isRunning = true; }
	void QuitScene() { _isRunning = false; }
	bool isQuitting() { return _isRunning; }

	template<class T>
	T* CreateEntity();

	template<class T>
	T* GetEntity();

	template<class T>
	std::vector<T*> GetEntities();
};

template<class T>
T* Scene::CreateEntity()
{
	T* entity = new T();
	entityList.push_back(entity);
	return entity;
}

template<class T>
inline T* Scene::GetEntity()
{
	for (Entity* e : entityList) {
		if (T* t = dynamic_cast<T*>(e)) {
			return t;
		}
	}

	return nullptr;
}

template<class T>
inline std::vector<T*> Scene::GetEntities()
{
	std::vector<T*> entitiesList;

	for (Entity* e : entityList) {
		if (T* t = dynamic_cast<T*>(e)) {
			entitiesList.push_back(t);
		}
	}

	return entitiesList;
}

#endif // !SCENE
