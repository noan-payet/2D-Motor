#ifndef _H__WALL
#define _H__WALL

#include "moteur2d/Header_Files/Entity.h"

class Wall : public Entity
{
public:
	void Update() override;
};

#endif // !_H__WALL