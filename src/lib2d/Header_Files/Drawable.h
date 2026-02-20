#ifndef DRAWABLE
#define DRAWABLE

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>

class Window;

class Drawable
{
public:
	virtual void Draw(Window* window) = 0;
};

#endif // !DRAWABLE
