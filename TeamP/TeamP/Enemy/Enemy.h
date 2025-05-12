#pragma once

class Enemy : public Circle
{
private:
	const int SPEED = 300;
	const int MAX_HP = 30;
	const float DAMAGE_INTERVAL = 0.3f;
	const float FIRE_INTERVAL = 1.0f;
	const int FIRE_COUNT = 10;

public:
	Enemy();
	~Enemy();

	void Update();
	void Render(HDC hdc);
	void Spawn(Vector2 pos);

	void SetPlayer(Player* player) { this->player = player; }
private:
	void Move();
	void Damaged();
	void Fire();

private:
	int hp = 0;
	float phaseTimer = 0;
	float damageTimer = 0;
	float fireTimer = 0;
	bool isDamaged = false;

	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;

	Player* player = nullptr;
};