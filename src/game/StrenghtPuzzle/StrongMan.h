#ifndef _H__STRONGMAN
#define _H__STRONGMAN

#include "moteur2d/Header_Files/Entity.h"

class StrongMan : public Entity
{
public:
	void Update() override;

private:
	float speed = 50.f;
	bool direction[4] = { true, true, true, true }; // up, down, left, right

public:
	void Collision(bool* side);
};

#endif // !_H__STRONGMAN