#ifndef WINDOW
#define WINDOW

#define WINDOW_WIDTH 1266
#define WINDOW_HEIGHT 800

#define TARGET_FPS 60
#define TARGET_DELTA_TIME 1.f / TARGET_FPS

#include "Drawable.h"

class Window
{
private:
	SDL_Window* _window     = nullptr;
	SDL_Renderer* _renderer = nullptr;

public:
	Window();

	void draw(Drawable* d);

	void clear() const;
	void Present() const;

	void CreateOurWindow(std::string title, int windowWidth, int windowHeight);
	bool isOpen();
	bool isRender();

	SDL_Renderer* GetRenderer() const { return _renderer; }

	friend class Sprite;
	friend class Entity;

	~Window();
};

#endif // !WINDOW