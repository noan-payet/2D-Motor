#include "Header_Files/Window.h"

Window::Window()
{
}

void Window::clear() const
{
	SDL_RenderClear(_renderer);
}

void Window::Present() const
{
	SDL_RenderPresent(_renderer);
}

void Window::CreateOurWindow(std::string title, int windowWidth, int windowHeight)
{
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow(title.c_str(), windowWidth, windowHeight, SDL_WINDOW_OPENGL);
	_renderer = SDL_CreateRenderer(_window, NULL);
}

bool Window::isOpen()
{
	if (!_window)
	{
		std::cout << "SDL_CreateWindow Error : "   << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	return true;
}

bool Window::isRender()
{
	if (!_renderer)
	{
		std::cout << "SDL_CreateRenderer Error : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(_window);
		SDL_Quit();
		return false;
	}

	return true;
}

void Window::draw(Drawable* d)
{
	d->Draw(this);
}

Window::~Window()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}