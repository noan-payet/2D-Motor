#ifndef _H__SKILL_TREE
#define _H__SKILL_TREE

#include "lib2d/Header_Files/Sprite.h"
#include "lib2d/Header_Files/Input.h"

#include "moteur2d/Header_Files/Entity.h"

class Skill_Tree : public Entity
{
private:
	float _deltaTime = 0.f;

public:
	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

private:
	int _skillNumber = 0;

public:
	void SetSkillNumber(int number) { _skillNumber = number; }
	int GetSkillNumber() const { return _skillNumber; }
};

#endif // !_H__SKILL_TREE