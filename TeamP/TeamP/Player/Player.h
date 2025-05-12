#pragma once

// 할일 : Fire()완성하기 + 총 갯수 늘리는 작업하기(아이템 먹으면 증가하게. 매개변수를 줘야되나) +
//	      궁극기 구현하기 (개쎈 레이저 쏘자) + 체력, 궁극기 게이지바 만들기
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
	void DrawingPlayer(HDC hdc); // 플레이어 모양 그리기
	HPEN ChangePen(); // 데미지입으면 선 색 바꾸기

	void Fire(); // 총쏘기
	void SpecialFire(); // 궁극기 쏘기

	void ItemGet(); // 아이템 닿으면 능력치 조정하기

	void ShowHealthPointBar(); // 체력바 보이기
	void ShowSpacialGaugeBar(); // 궁극기바 보이기


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