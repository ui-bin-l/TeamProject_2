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
	float attackTimer = 0.0f; // ���� �ֱ� Ÿ�̸�
	float fireTimer = 0.0f;
	float bulletTimer = 0.0f;
	float targetY = 300.0f; // �����ؾ� �� Y ��ġ
	float xDirection = 1.0f; // X�� �̵� ���� (1: ������, -1: ����)
	float xSpeed = 150.0f;   // X�� �̵� �ӵ�
	float bulletSpeed = 500.0f; // �Ѿ� �ӵ�
	bool reachedY = false;   // ��ǥ Y�� �����ߴ��� ����
	PatternType attackPattern = PatternType::StraightBullet;
};