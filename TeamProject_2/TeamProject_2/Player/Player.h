#pragma once

class Player : public Circle
{
private:
	const float MAX_SPEED = 100.0f;
	const int PEN_WIDTH = 5;
	const int MAX_SPACIAL_GAUGE = 10;

public:

	Player();
	~Player();

	void Update();
	void Render();

	float GetSpeed() { return speed; }
	float GetBulletSpeed() { return bulletSpeed; }
	int GetBulletPower() { return bulletPower; }

	void SetSpeed(float newSpeed) { speed = newSpeed; }
	void SetBulletSpeed(float newSpeed) { bulletSpeed = newSpeed; }
	int SetBulletPower(int newPower) { bulletPower = newPower; }

	void Move();
	void DrawingPlayer();
	HPEN ChangePen();

	void Fire();
	void SpecialFire();

	void ItemGet();

private:

	int healthPoint = 100;
	int spacialGauge = 0;
	float speed = 10.0f;
	float bulletSpeed = 10.0f;
	int bulletPower = 10;

	HPEN pen;
	HPEN originalPen;
	HPEN damagePen;
};