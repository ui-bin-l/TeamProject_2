#pragma once

class Boss : public Enemy
{
private:
	enum class PatternType
	{
		StraightBullet,
		CrossBullet,
		SpreadBullet,

	};

	int SPEED = 300;

public:
	Boss();
	~Boss();
	void Fire() override;
	void Move();
	void ChangePattern();
	void Update() override;
private:
	float attackTimer = 0.0f; // 공격 주기 타이머
	float fireTimer = 0.0f;
	float bulletTimer = 0.0f;
	float targetY = 300.0f; // 도달해야 할 Y 위치
	float xDirection = 1.0f; // X축 이동 방향 (1: 오른쪽, -1: 왼쪽)
	float xSpeed = 150.0f;   // X축 이동 속도
	float bulletSpeed = 500.0f; // 총알 속도
	bool reachedY = false;   // 목표 Y에 도달했는지 여부
	PatternType attackPattern = PatternType::StraightBullet;
};