#include "Framework.h"
#include "Player.h"

Player::Player() :Circle(15)
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
	//ChangePen(); //이렇게 사용이되나?
	ItemGet();

	Fire();

}

void Player::Render(HDC hdc)
{
	DrawingPlayer(hdc);

	ShowHealthPointBar();
	ShowSpacialGaugeBar();
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT) && center.x > 0)
	{
		center.x -= DELTA * speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) && center.x < SCREEN_WIDTH)
	{
		center.x += DELTA * speed;
	}
	if (GetAsyncKeyState(VK_UP) && center.y > 0)
	{
		center.y -= DELTA * speed;
	}
	if (GetAsyncKeyState(VK_DOWN) && center.y < SCREEN_HEIGHT)
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

//void Player::ChangePen()
//{
//	if (BulletManager::Get()->IsCollision(this, "player"))
//	{
//		pen = damagePen;
//		return;
//	}
//	pen = originalPen;
//}

void Player::Fire()
{
	countFireTime += DELTA;
	if (countFireTime < fireTime)
		return;

	switch (gunState)
	{
	case UpBullet:
		PlayerBulletManager::Get()->Fire({ center.x,center.y - radius });
		break;
	case DownBullet:
		PlayerBulletManager::Get()->DownFire({ center.x,center.y + radius });
		break;
	case ShotGunBullet:
	case CrossBullet:
		PlayerBulletManager::Get()->CrossFire({ center.x,center.y });
		break;
	case CrazyBullet:
	case CircleBullet:
		PlayerBulletManager::Get()->CircleFire(center);
		break;

	case EndBullet:
	default:
		break;
	}

	countFireTime = 0.0f;
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
		speed += 10.0f;
		pen = damagePen;
		break;
	case BulletSpeed:
		if (fireTime < 0.2f)
			fireTime = 0.2f;
		else
		{
			fireTime -= 0.1f;
		}
		break;
	case BulletPower:
		bulletPower += 5;
		break;
	case ChangeGun:
	{
		int random = rand() % BulletType::EndBullet;
		gunState = (BulletType)random; 
	}
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
