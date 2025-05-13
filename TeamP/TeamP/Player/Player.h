#pragma once

// 할일 : 충돌처리하기
class Player : public Circle
{
private:
	const int PEN_WIDTH = 5;
	const int MAX_SPACIAL_GAUGE = 10;
	const float PRINT_TIME = 3.0f;
	const int MAX_HEALTH_POINT = 100;
	const int BAR_HEIGHT = 10;
	const int SPACE = 5;
	const float DAMAGE_TIME = 0.5f;

public:

	Player();
	~Player();

	void Update();
	void Render(HDC hdc);

	//float GetSpeed() { return speed; }
	//float GetBulletSpeed() { return bulletSpeed; }
	int GetBulletPower() { return bulletPower; }

	//void SetSpeed(float newSpeed) { speed = newSpeed; }
	//void SetBulletSpeed(float newSpeed) { bulletSpeed = newSpeed; }
	//int SetBulletPower(int newPower) { bulletPower = newPower; }

	void Move();
	void DrawingPlayer(HDC hdc); // 플레이어 모양 그리기
	void ChangePen(); // 데미지입으면 선 색 바꾸기

	void Fire(); // 총쏘기
	void SpecialFire(); // 궁극기 쏘기

	void ItemGet(); // 아이템 닿으면 능력치 조정하기

	void ShowHealthPointBar(HDC hdc); // 체력바 보이기

	void PrintItemName(HDC hdc);

	int ChangeHp();

	void Damage();


private:

	int healthPoint = 100;
	int spacialGauge = 0;
	float speed = 1000.0f;
	int bulletPower = 10;
	bool isGetItem = false;

	bool isDamage = false;
	float damageTime = 0.0f;

	float countFireTime = 0.0f;
	float fireTime = 0.5f;
	float printTime = 0.0f;

	HPEN pen;
	HPEN originalPen;
	HPEN damagePen;

	HBRUSH hBrush;
	HBRUSH barColor[3];

	BulletType gunState = UpBullet;
	wstring getItemName = L"";
};