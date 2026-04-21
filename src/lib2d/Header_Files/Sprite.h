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

public:
	Sprite(std::string, Position position);

	void Draw(Window* window) override;

	void loadSprite(Window* window);

	float GetWidth() const;
	float GetHeight() const;

	void SetWidth(float width);
	void SetHeight(float height);

	void Resize(float w, float h);

	Vector2f GetHitbox(float anchorX = 0.f, float anchorY = 0.f);
	void SetHitbox(Vector2f newPos, float anchorX = 0.f, float anchorY = 0.f);

	~Sprite();
};
#endif // !SPRITE
