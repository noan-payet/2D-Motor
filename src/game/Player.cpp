#include "game/Player.h"
#include "lib2d/Header_Files/Window.h"

void Player::InitEntity(Window* window, std::string path, float deltaTime, Vector2f pos)
{
	SetPos(pos);
	_spritePlayer = new Sprite(GetPos(), path);
	_spritePlayer->loadSprite(window);
	_spritePlayer->Resize(100.f, 100.f);

	_deltaTime = deltaTime;

	// STATE MACHINE
	{
		_stateMachine.AddState(new PlayerIdleState());

		Transition<Player>* shootTransition = _stateMachine.AddTransition((int)PlayerState::IDLE, (int)PlayerState::SHOOTING);
		shootTransition->AddCondition(new PlayerShootCondition());
	}

	{
		_stateMachine.AddState(new PlayerShootingState());

		Transition<Player>* shootTransition = _stateMachine.AddTransition((int)PlayerState::SHOOTING, (int)PlayerState::IDLE);
		shootTransition->AddCondition(new PlayerShootCondition(false));
	}

	_stateMachine.Initialize(this, (int)PlayerState::IDLE);
}

void Player::Update()
{ 
	Position _playerPos = Position({0.f, 0.f});

	if (_spritePlayer->GetHitbox().GetY() < 0)
		_playerPos.SetPos(_playerPos.GetPos().operator=({ _spritePlayer->GetPos().GetX(), 0.f }));
	if (_spritePlayer->GetHitbox().GetX() < 0)
		_playerPos.SetPos(_playerPos.GetPos().operator=({ 0.f, _spritePlayer->GetPos().GetY() }));
	if (_spritePlayer->GetHitbox(0.f, 1.f).GetY() > WINDOW_HEIGHT)
		_playerPos.SetPos(_playerPos.GetPos().operator=({ _spritePlayer->GetPos().GetX(), 0.f }));
	if (_spritePlayer->GetHitbox(1.f, 0.f).GetX() > WINDOW_WIDTH)
		_playerPos.SetPos(_playerPos.GetPos().operator=({ 0.f, _spritePlayer->GetPos().GetY() }));

	if (Input::getInstance().isKeyHeld(SDLK_Z) || Input::getInstance().isKeyHeld(SDLK_UP))
	{
		_playerPos.SetPos({ _playerPos.GetPos().GetX(), -(_spritePlayer->GetPos().GetY() - 300.f * _deltaTime)});
	}
	if (Input::getInstance().isKeyHeld(SDLK_Q) || Input::getInstance().isKeyHeld(SDLK_LEFT))
	{
		_playerPos.SetPos({ -(_spritePlayer->GetPos().GetX() - 300.f * _deltaTime),  _playerPos.GetPos().GetY() });
	}
	if (Input::getInstance().isKeyHeld(SDLK_S) || Input::getInstance().isKeyHeld(SDLK_DOWN))
	{
		_playerPos.SetPos({ _playerPos.GetPos().GetX(), _spritePlayer->GetPos().GetY() + 300.f * _deltaTime });
	}
	if (Input::getInstance().isKeyHeld(SDLK_D) || Input::getInstance().isKeyHeld(SDLK_RIGHT))
	{
		_playerPos.SetPos({ _spritePlayer->GetPos().GetX() + 300.f * _deltaTime,  _playerPos.GetPos().GetY() });
	}

	_spritePlayer->SetPos(_spritePlayer->GetPos().operator+(_playerPos.GetPos().Normalise().operator*(10)));
	SetPos(_spritePlayer->GetHitbox(0.5f, -1.f));

	_stateMachine.Update(this, _deltaTime);

	switch ((PlayerState)_stateMachine.GetState())
	{
		case PlayerState::IDLE:
			std::cout << "IDLE\n";
			break;

		case PlayerState::SHOOTING:
			std::cout << "SHOOTING\n";
			break;
	}
}

void Player::Draw(Window* window)
{
	_spritePlayer->Draw(window);
}

bool Player::PlayerShoot()
{
	if (Input::getInstance().isKeyHeld(SDLK_SPACE)) // Shoot bullet
	{
		return true;
	}

	return false;
}

void PlayerIdleState::Start(Player* player)
{
	player->shootCooldown = 0.1f;
}

void PlayerIdleState::Update(Player* player, float dt)
{
	if (player->shootCooldown <= 0)
	{
		player->canShoot = true;
	}

	player->shootCooldown -= dt;
}

void PlayerIdleState::End(Player* player)
{
}

void PlayerShootingState::Start(Player* player)
{
	player->canShoot = false;
}

void PlayerShootingState::Update(Player* player, float dt)
{
	
}

void PlayerShootingState::End(Player* player)
{
}

bool PlayerShootCondition::Test(Player* player)
{
	return player->canShoot && player->PlayerShoot();
}