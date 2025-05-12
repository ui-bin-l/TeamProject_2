#pragma once

// ���� : Fire()�ϼ��ϱ� + �� ���� �ø��� �۾��ϱ�(������ ������ �����ϰ�. �Ű������� ��ߵǳ�) +
//	      �ñر� �����ϱ� (���� ������ ����) + ü��, �ñر� �������� �����
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
	void Render(HDC hdc);

	float GetSpeed() { return speed; }
	float GetBulletSpeed() { return bulletSpeed; }
	int GetBulletPower() { return bulletPower; }

	void SetSpeed(float newSpeed) { speed = newSpeed; }
	void SetBulletSpeed(float newSpeed) { bulletSpeed = newSpeed; }
	int SetBulletPower(int newPower) { bulletPower = newPower; }

	void Move();
	void DrawingPlayer(HDC hdc); // �÷��̾� ��� �׸���
	HPEN ChangePen(); // ������������ �� �� �ٲٱ�

	void Fire(); // �ѽ��
	void SpecialFire(); // �ñر� ���

	void ItemGet(); // ������ ������ �ɷ�ġ �����ϱ�

	void ShowHealthPointBar(); // ü�¹� ���̱�
	void ShowSpacialGaugeBar(); // �ñر�� ���̱�


private:

	int healthPoint = 100;
	int spacialGauge = 0;
	float speed = 1000.0f;
	float bulletSpeed = 10.0f;
	int bulletPower = 10;

	HPEN pen;
	HPEN originalPen;
	HPEN damagePen;
};