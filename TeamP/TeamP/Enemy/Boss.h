#pragma once

class Boss : public Enemy
{
private:
	int SPEED = 300;

public:
	Boss();
	~Boss();
	void Fire() override;
	void Move();
private:
	float fireTimer = 0.0f;
	float bulletTimer = 0.0f;
	float targetY = 150.0f; // 도달해야 할 Y 위치
	float xDirection = 1.0f; // X축 이동 방향 (1: 오른쪽, -1: 왼쪽)
	float xSpeed = 100.0f;   // X축 이동 속도
	bool reachedY = false;   // 목표 Y에 도달했는지 여부
};