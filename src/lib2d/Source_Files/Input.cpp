#include "Header_Files/Input.h"
#include <map>

Input& Input::getInstance()
{
	static Input input;
	return       input;
}

bool Input::isKeyDown(SDL_Keycode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key, NULL);
	return _previousKeyboardState[scancode] == 0 && _key_states[scancode] == 1;
}

bool Input::isKeyHeld(SDL_Keycode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key, NULL);
	return _key_states[scancode];
}

bool Input::isKeyUp(SDL_Keycode key)
{
	SDL_Scancode scancode = SDL_GetScancodeFromKey(key, NULL);
	return _previousKeyboardState[scancode] == 1 && _key_states[scancode] == 0;
}

bool Input::Update()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDLK_ESCAPE:
			return false;

		case SDL_EVENT_QUIT:
			return false;
		}
	}

	std::memcpy(_previousKeyboardState, _key_states, SDL_SCANCODE_COUNT * sizeof(Uint8));
	SDL_PumpEvents();

	return true;
}