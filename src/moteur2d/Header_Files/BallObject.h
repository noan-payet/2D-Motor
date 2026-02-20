#ifndef BALLOBJECT
#define BALLOBJECT

#include "Header_Files/Sprite.h"
#include "Header_Files/Entity.h"
#include "Header_Files/Window.h"

class BallObject : public Entity
{
private:
	Sprite* _ballSprite;
	Entity* _ballEntity;
public:
	BallObject(Position pos, Window* window);

	void Update() override;
};

#endif

