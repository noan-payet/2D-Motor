#ifndef _H__STRONGMAN
#define _H__STRONGMAN

#include "moteur2d/Header_Files/Entity.h"

class StrongMan : public Entity
{
public:
	void Update() override;

private:
	float speed = 150.f;
	bool direction[4] = { true, true, true, true }; // up, down, left, right

	bool collision;

public:
	void Collision(std::vector<bool>);

	void Push(Entity* otherEntity, std::vector<bool> side);

	bool IsMoving() const { return collision; }
	void SetIsMoving(bool moving) { collision = moving; }
};

#endif // !_H__STRONGMAN