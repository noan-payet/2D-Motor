#include "Header_Files/Sprite.h"
#include "Header_Files/Window.h"

Sprite::Sprite(std::string path, Position position, bool isSheet)
	: _path(path), Position(position), isSpriteSheet(isSheet)
{
	_width = 0.f;
	_height = 0.f;

	_newWidth = _width;
	_newHeight = _height;

	newSizeX = newSizeY = 0;
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

	if (isSpriteSheet == false)
		SDL_RenderTexture(window->_renderer, _texture, NULL, &rectShow);
	else
		SDL_RenderTexture(window->_renderer, _texture, &rect, &rectShow);
}

void Sprite::Transparence(int trans)
{
	SDL_SetTextureAlphaMod(_texture, trans);
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