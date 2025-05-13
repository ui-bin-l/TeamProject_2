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
	float targetY = 150.0f; // �����ؾ� �� Y ��ġ
	float xDirection = 1.0f; // X�� �̵� ���� (1: ������, -1: ����)
	float xSpeed = 100.0f;   // X�� �̵� �ӵ�
	bool reachedY = false;   // ��ǥ Y�� �����ߴ��� ����
};