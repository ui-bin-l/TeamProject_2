#include "Framework.h"
#include "Player.h"

Player::Player() :Circle(30)
{
	center = { SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.9 };
	originalPen = CreatePen(PS_SOLID, PEN_WIDTH, RGB(250, 200, 130));
	damagePen = CreatePen(PS_SOLID, PEN_WIDTH, RGB(250, 100, 100));
}

Player::~Player()
{
	DeleteObject(originalPen);
	DeleteObject(damagePen);
}

void Player::Update()
{
	Move();
	pen = ChangePen(); //이렇게 사용이되나?
	ItemGet();
}

void Player::Render(HDC hdc)
{
	DrawingPlayer(hdc);
	Fire();
	ShowHealthPointBar();
	ShowSpacialGaugeBar();
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT) && center.x > 0)
	{
		center.x -= DELTA * speed;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && center.x < SCREEN_WIDTH)
	{
		center.x += DELTA * speed;
	}
	else if (GetAsyncKeyState(VK_UP) && center.y > 0)
	{
		center.y -= DELTA * speed;
	}
	else if (GetAsyncKeyState(VK_DOWN) && center.y < SCREEN_HEIGHT)
	{
		center.y += DELTA * speed;
	}
}

void Player::DrawingPlayer(HDC hdc)
{
	printf("Player Draw at (%.1f, %.1f)\n", center.x, center.y);


	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	Vector2 leftAndUp = { center.x - radius ,center.y - radius };
	Vector2 rightAndDown = { center.x + radius ,center.y + radius };

	MoveToEx(hdc, center.x, leftAndUp.y, nullptr);
	LineTo(hdc, leftAndUp.x, rightAndDown.y);

	MoveToEx(hdc, center.x, leftAndUp.y, nullptr);
	LineTo(hdc, rightAndDown.x, rightAndDown.y);

	MoveToEx(hdc, leftAndUp.x, rightAndDown.y, nullptr);
	LineTo(hdc, rightAndDown.x, rightAndDown.y);

	MoveToEx(hdc, center.x, rightAndDown.y, nullptr);
	LineTo(hdc, leftAndUp.x, center.y);

	MoveToEx(hdc, center.x, rightAndDown.y, nullptr);
	LineTo(hdc, rightAndDown.x, center.y);

	MoveToEx(hdc, leftAndUp.x, center.y, nullptr);
	LineTo(hdc, rightAndDown.x, center.y);

	SelectObject(hdc, oldPen);

}

HPEN Player::ChangePen()
{
	if (BulletManager::Get()->IsCollision(this, "player")) return damagePen;
	return originalPen;
}

void Player::Fire()
{
	BulletManager::Get()->Fire(center, "player");
}

void Player::SpecialFire()
{
	if (GetAsyncKeyState('Q') && spacialGauge == MAX_SPACIAL_GAUGE)
	{
		// bulletmanager에서 일시적으로 나가는 선을 구현할까 음 레이저? 아니면 엄청 큰 총알?
		spacialGauge = 0;
	}
}

void Player::ItemGet()
{
	ItemType getItem = ItemManager::Get()->GetItem(this);

	switch (getItem)
	{
	case PlayerSpeed:
		speed += 5.0f * DELTA;
		break;
	case BulletSpeed:
		bulletSpeed += 5.0f * DELTA;
		break;
	case BulletPower:
		bulletPower += 5;
		break;
	case AddGun:
		// 총 추가 구현
		break;
	case End:
		break;
	default:
		break;
	}
}

void Player::ShowHealthPointBar()
{
}

void Player::ShowSpacialGaugeBar()
{
}
