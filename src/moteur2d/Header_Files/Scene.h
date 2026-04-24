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
	void QuitScene() { entityList.clear(); _isRunning = false; }
	bool isQuitting() { return _isRunning; }

	template<class T>
	T* CreateEntity();

	template<class T>
	T* GetEntity();

	template<class T>
	void EraseEntity(T* entity);

	template<class T>
	std::vector<T*> GetEntities();

	template<class T>
	Uint8 GetPixelOnScreen(Window* window, Vector2f pos, int squareSize);
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
inline void Scene::EraseEntity(T* entity)
{
	for (std::size_t i = entityList.size(); i > 0; --i) {
		size_t idx = i - 1;
		if (T* t = dynamic_cast<T*>(entityList[idx])) {
			if (entity == t)
				entityList.erase(entityList.begin() + idx);
		}
	}
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

template<class T>
inline Uint8 Scene::GetPixelOnScreen(Window* window, Vector2f pos, int squareSize)
{
	for (Entity* e : entityList) {
		if (T* t = dynamic_cast<T*>(e)) {
			return t->GetSprite()->GetPixel(window, pos, squareSize);
		}
	}
}

#endif // !SCENE
