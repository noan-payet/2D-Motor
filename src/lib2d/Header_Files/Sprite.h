#ifndef SPRITE
#define SPRITE

#include "lib2d/Header_Files/Position.h"
#include "lib2d/Header_Files/Drawable.h"

class Sprite : public Position, public Drawable
{
private:
	std::string _path;
	SDL_Texture* _texture = NULL;

	float _width, _height;
	float _newWidth, _newHeight;

	int newSizeX, newSizeY;

public:
	Sprite(std::string, Position position);

	void Draw(Window* window) override;

	void loadSprite(Window* window);

	float GetWidth() const;
	float GetHeight() const;

	float GetOriginalWidth() const { return _width; }
	float GetOriginalHeight() const { return _height; }

	void SetWidth(float width);
	void SetHeight(float height);

	void SetWidthInt(int x) { newSizeX = x; }
	void SetHeightInt(int y) { newSizeY = y; }

	void Resize(float w, float h);

	Vector2f GetHitbox(float anchorX = 0.f, float anchorY = 0.f);
	void SetHitbox(Vector2f newPos, float anchorX = 0.f, float anchorY = 0.f);

	~Sprite();
};
#endif // !SPRITE
