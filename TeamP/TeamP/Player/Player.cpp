#include "Framework.h"
#include "Player.h"

Player::Player() :Circle(15)
{
	center = { SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.9 };
	originalPen = CreatePen(PS_SOLID, PEN_WIDTH, RGB(255, 165, 100));
	damagePen = CreatePen(PS_SOLID, PEN_WIDTH, RGB(200, 0, 150));
	pen = originalPen;

	barColor[0] = CreateSolidBrush(RGB(0, 201, 87));
	barColor[1] = CreateSolidBrush(RGB(255, 193, 37));
	barColor[2] = CreateSolidBrush(RGB(255, 69, 0));
	hBrush = barColor[0];
}

Player::~Player()
{
	DeleteObject(pen);
}

void Player::Update()
{
	Move();
	ItemGet();

	Fire();
	if (isGetItem)
		printTime += DELTA;
	Damage();
	ChangePen();
}

void Player::Render(HDC hdc)
{
	DrawingPlayer(hdc);
	PrintItemName(hdc);
	ShowHealthPointBar(hdc);
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT) && center.x-radius > 0)
	{
		center.x -= DELTA * speed;
	}
	if (GetAsyncKeyState(VK_RIGHT) && center.x+radius < SCREEN_WIDTH)
	{
		center.x += DELTA * speed;
	}
	if (GetAsyncKeyState(VK_UP) && center.y-radius > 0)
	{
		center.y -= DELTA * speed;
	}
	if (GetAsyncKeyState(VK_DOWN) && center.y+radius < SCREEN_HEIGHT)
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

void Player::ChangePen()
{
	if (isDamage)
	{
		pen = damagePen;
		return;
	}
	pen = originalPen;
}

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
		PlayerBulletManager::Get()->ShotGunFire(center);
		break;
	case CrossBullet:
		PlayerBulletManager::Get()->CrossFire({ center.x,center.y });
		break;
	case CrazyBullet:
		PlayerBulletManager::Get()->CrazyFire(center);
		break;
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
		getItemName = L"이동속도 증가 아이템 획득!";
		isGetItem = true;
		printTime = 0.0f;
		speed += 10.0f;
		break;
	case BulletSpeed:
		getItemName = L"총알 속도 증가 아이템 획득!";
		isGetItem = true;
		printTime = 0.0f;
		if (fireTime < 0.2f)
			fireTime = 0.2f;
		else
		{
			fireTime -= 0.1f;
		}
		break;
	case BulletPower:
		getItemName = L"총알 파워 증가 아이템 획득!";
		isGetItem = true;
		printTime = 0.0f;
		bulletPower += 5;
		break;
	case ChangeGun:
	{
		getItemName = L"총 변경 아이템 획득!";
		isGetItem = true;
		printTime = 0.0f;
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

void Player::ShowHealthPointBar(HDC hdc)
{
	Vector2 hpBar = { center.x , center.y + SPACE };

	MoveToEx(hdc, hpBar.x - radius, hpBar.y + radius, nullptr);
	LineTo(hdc, hpBar.x + radius, hpBar.y + radius);

	MoveToEx(hdc, hpBar.x + radius, hpBar.y + radius, nullptr);
	LineTo(hdc, hpBar.x + radius, hpBar.y + radius + BAR_HEIGHT);

	MoveToEx(hdc, hpBar.x - radius, hpBar.y + radius + BAR_HEIGHT, nullptr);
	LineTo(hdc, hpBar.x + radius, hpBar.y + radius + BAR_HEIGHT);


	MoveToEx(hdc, hpBar.x - radius, hpBar.y + radius, nullptr);
	LineTo(hdc, hpBar.x - radius, hpBar.y + radius + BAR_HEIGHT);

	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, hpBar.x - radius, hpBar.y + radius, ChangeHp() + hpBar.x - radius, hpBar.y + radius + BAR_HEIGHT);
	SelectObject(hdc, oldBrush);
}

void Player::PrintItemName(HDC hdc)
{
	if (!isGetItem)
		return;
	if (printTime >= PRINT_TIME)
	{
		isGetItem = false;
	}
	else
	{
		COLORREF oldText = SetTextColor(hdc, RGB(10, 186, 181));
		TextOut(hdc, (int)(SCREEN_WIDTH * 0.3f), (int)(SCREEN_HEIGHT * 0.2f),
			getItemName.c_str(), getItemName.length());
		SetTextColor(hdc, oldText);
	}
}

int Player::ChangeHp()
{
	float ratio = (float)healthPoint / MAX_HEALTH_POINT;

	if (ratio > 0.6f)
		hBrush = barColor[0];    // 에메랄드 그린
	else if (ratio > 0.3f)
		hBrush = barColor[1];      // 골든 옐로우
	else
		hBrush = barColor[2];   // 오렌지 레드

	return ratio * radius * 2;
}

void Player::Damage()
{
	damageTime += DELTA;
	if (damageTime >= DAMAGE_TIME)
	{
		isDamage = false;
		damageTime = 0.0f;
	}
	if (EnemyBulletManager::Get()->IsCollision(this))
	{
		healthPoint -= 50;
		damageTime = 0.0f;
		isDamage = true;
	}
	else if (EnemyManager::Get()->IsCollision(this))
	{
		healthPoint -= 1;
		damageTime = 0.0f;
		isDamage = true;
	}

	if (healthPoint <= 0)
		SceneManager::Get()->ChangeScene("GameOver");
		
}

