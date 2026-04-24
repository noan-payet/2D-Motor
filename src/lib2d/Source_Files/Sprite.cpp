#include "Header_Files/Sprite.h"
#include "Header_Files/Window.h"

Sprite::Sprite(Position position, std::string path, bool isSheet)
	: _path(path), Position(position), isSpriteSheet(isSheet)
{
	_width = 0.f;
	_height = 0.f;

	_newWidth = _width;
	_newHeight = _height;

	newSizeX = newSizeY = 0;
}

Uint8 Sprite::GetPixel(Window* window, Vector2f pos, int squareSize)
{
	SDL_Rect rect = { pos.GetX(), pos.GetY(), squareSize, squareSize };

	// On récupère les pixels du renderer dans une surface
	SDL_Surface* surface = SDL_RenderReadPixels(window->_renderer, &rect);

	if (surface) {
		// On accède aux données du pixel
		Uint8 r, g, b, a;
		Uint32* pixels = (Uint32*)surface->pixels;
		Uint32 pixelValue = pixels[0];

		// On décompose la couleur selon le format de la surface
		SDL_GetRGBA(pixelValue, 
			SDL_GetPixelFormatDetails(surface->format), 
			NULL, 
			&r, &g, &b, &a);

		// Toujours libérer la surface après usage !
		SDL_DestroySurface(surface);

		return r, g, b;
	}

	return 0;
}

void Sprite::loadSprite(Window* window)
{
	_texture = IMG_LoadTexture(window->_renderer, _path.c_str());

	if (!_texture)
	{
		std::cout << "Texture has not load : " << SDL_GetError() << std::endl;
	}

	SDL_GetTextureSize(_texture, &_width, &_height);

	_newWidth = _width;
	_newHeight = _height;
}

float Sprite::GetWidth() const
{
	return _newWidth;
}

float Sprite::GetHeight() const
{
	return _newHeight;
}

void Sprite::SetWidth(float width)
{
	_newWidth = width;
}

void Sprite::SetHeight(float height)
{
	_newHeight = height;
}

void Sprite::Draw(Window* window)
{
	SDL_FRect rectShow = { GetPos().GetX(), GetPos().GetY(), _newWidth, _newHeight };
	SDL_FRect rect = { newSizeX, newSizeY, _newWidth, _newHeight };

	SDL_SetTextureAlphaMod(_texture, _alpha);

	if (isSpriteSheet == false)
		SDL_RenderTexture(window->_renderer, _texture, NULL, &rectShow);
	else
		SDL_RenderTexture(window->_renderer, _texture, &rect, &rectShow);
}

void Sprite::DrawLine(Window* window, Vector2f start, Vector2f end, Uint8 alpha)
{
	SDL_SetRenderDrawColor(window->_renderer, 255, 255, 255, alpha);
	SDL_RenderLine(window->_renderer, start.GetX(), start.GetY(), end.GetX(), end.GetY());

	SDL_SetRenderDrawColor(window->_renderer, 0, 0, 0, 255);
}

void Sprite::SetAlpha(int trans)
{
	_alpha = trans;

	if (_alpha > 255)
		_alpha = 255;
}

void Sprite::Resize(float w, float h)
{
	float factorWidth = w / _newWidth;
	float factorHeight = h / _newHeight;

	float factorMin = std::min(factorWidth, factorHeight);

	_newWidth *= factorMin;
	_newHeight *= factorMin;
}

Vector2f Sprite::GetHitbox(float anchorX, float anchorY)
{
	Vector2f pos = { 0, 0 };
	pos.SetX(_position.GetX() + _width * anchorX);
	pos.SetY(_position.GetY() + _height * anchorY);

	return pos;
}

void Sprite::SetHitbox(Vector2f newPos, float anchorX, float anchorY)
{
	_position.SetX(newPos.GetX() - _width * anchorX);
	_position.SetY(newPos.GetY() - _height * anchorY);
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(_texture);
}