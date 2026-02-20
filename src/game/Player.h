#ifndef PLAYER
#define PLAYER

#include "lib2d/Header_Files/Sprite.h"
#include "lib2d/Header_Files/Input.h"
#include "moteur2d/Header_Files/Entity.h"
#include "moteur2d/Header_Files/StateMachine.h"

class Player : public Entity
{
private:
	Sprite* _spritePlayer = nullptr;

	float _deltaTime = 0.f;

	int playerLife = 0;

	bool canShoot = false;
	float shootCooldown = 0.f;

public:
	Player() {}

	void InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos) override;

	void Update() override;

	void Draw(Window* window) override;

private:
	StateMachine<Player> _stateMachine;

	// STATES
	friend class PlayerIdleState;
	friend class PlayerShootingState;

	// CONDITIONS
	friend class PlayerShootCondition;

public:
	bool PlayerShoot();
	StateMachine<Player>* GetStateMachine() { return &_stateMachine; }

	enum class PlayerState
	{
		IDLE,
		SHOOTING,

		Count
	};
};

class PlayerIdleState : public StateBase<Player>
{
public:
	void Start(Player* player) override;
	void Update(Player* player, float dt) override;
	void End(Player* player) override;
};

class PlayerShootingState : public StateBase<Player>
{
public:
	void Start(Player* player) override;
	void Update(Player* player, float dt) override;
	void End(Player* player) override;
};

// CONDITIONS

class PlayerShootCondition : public Condition<Player>
{
public:
	PlayerShootCondition(bool expectedValue = true) : Condition(expectedValue) {}
	bool Test(Player* player) override;
};

#endif // !PLAYER
