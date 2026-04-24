#ifndef _H__STRONGMAN
#define _H__STRONGMAN

#include "lib2d/Header_Files/Input.h"

#include "moteur2d/Header_Files/Entity.h"

class StrongMan : public Entity
{
public:
	void Update() override;
};

#endif // !_H__STRONGMAN