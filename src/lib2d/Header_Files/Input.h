#ifndef INPUT
#define INPUT

#include <SDL3/SDL.h>
#include "lib2d/Header_Files/Vector2f.h"

class Input
{
private:
	Input() 
	{
		_key_states = SDL_GetKeyboardState(nullptr);
	}

	Input(const Input&) = delete;
	 
	const bool* _key_states;
	Uint8 _previousKeyboardState[SDL_SCANCODE_COUNT] = { 0 };

	SDL_Event event;

public:
	static Input& getInstance();

	bool isKeyDown(SDL_Keycode key);
	bool isKeyHeld(SDL_Keycode key);
	bool isKeyUp(SDL_Keycode key);

	Vector2f GetMousePosition() const;
	void ShowMouseCursor() { SDL_ShowCursor(); }
	void HideMouseCursor() { SDL_HideCursor(); }

	bool Update();
};

#endif // !INPUT

