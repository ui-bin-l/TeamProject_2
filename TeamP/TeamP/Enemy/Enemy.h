#pragma once

class Enemy : public Circle
{
protected:
	const int SPEED = 150;
	const float DAMAGE_INTERVAL = 0.1f;
	const float FIRE_INTERVAL = 0.5f;
	const int FIRE_COUNT = 10;


public:
	Enemy();
	~Enemy();

	void virtual Update();
	void Render(HDC hdc);
	void Spawn(Vector2 pos);
	void virtual Fire() = 0;
	void SetPlayer(Player* player) { this->player = player; }
	void SetPhase(int phase) { this->phase = phase; }
	void virtual Move();
	void Damaged();
protected:
	int radius = 20;
	int hp = 0;
	float damageTimer = 0;
	float fireTimer = 0;
	int phase = 0;
	bool isDamaged = false;

	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;
	HBRUSH hNeonBlueBrush;
	HBRUSH hNeonGreenBrush;
	HBRUSH hNeonPinkBrush;
	HBRUSH hNeonPurpleBrush;

protected:
	Player* player = nullptr;
};