#include "Header_Files/Sprite.h"
#include "Header_Files/Window.h"

Sprite::Sprite(std::string path, Position position)
	: _path(path), Position(position) 
{
	_width = 0.f;
	_height = 0.f;
}

void Sprite::loadSprite(Window* window)
{
	_texture = IMG_LoadTexture(window->_renderer, _path.c_str());

	if (!_texture)
	{
		std::cout << "Texture has not load : " << SDL_GetError() << std::endl;
	}

	SDL_GetTextureSize(_texture, &_width, &_height);
}

float Sprite::GetWidth() const
{
	return _width;
}

float Sprite::GetHeight() const
{
	return _height;
}

void Sprite::SetWidth(float width)
{
	_width = width;
}

void Sprite::SetHeight(float height)
{
	_height = height;
}

void Sprite::Draw(Window* window)
{
	SDL_FRect rect = { GetPos().GetX(), GetPos().GetY(), _width, _height};
	SDL_RenderTexture(window->_renderer, _texture, NULL, &rect);
}

void Sprite::Resize(float w, float h)
{
	float factorWidth = w / _width;
	float factorHeight = h / _height;

	float factorMin = std::min(factorWidth, factorHeight);

	_width *= factorMin;
	_height *= factorMin;
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