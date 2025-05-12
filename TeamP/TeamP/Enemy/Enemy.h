#pragma once

class Enemy : public Circle
{
protected:
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
	void virtual Fire() = 0;
	void SetPlayer(Player* player) { this->player = player; }
	void SetPhase(int phase) { this->phase = phase; }
private:	
	void Move();
	void Damaged();
	

protected:
	int hp = 0;
	float damageTimer = 0;
	float fireTimer = 0;
	int phase = 0;
	bool isDamaged = false;

	HBRUSH hRedBrush;
	HBRUSH hBlueBrush;
	HBRUSH hSelectBrush;
protected:
	Player* player = nullptr;
};