#ifndef _H__MOVABLE
#define _H__MOVABLE

#include "moteur2d/Header_Files/Entity.h"

class Movable_Object : public Entity
{
public:
	void Update() override;
};

#endif // !_H__MOVABLE