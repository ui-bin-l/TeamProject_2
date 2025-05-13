#include "Framework.h"

Enemy::Enemy() : Circle(30)
{
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hNeonBlueBrush = CreateSolidBrush(RGB(0, 255, 255));
	hNeonGreenBrush = CreateSolidBrush(RGB(57, 255, 20));
	hNeonPinkBrush = CreateSolidBrush(RGB(255, 20, 147));
	hSelectBrush = hBlueBrush;
}

Enemy::~Enemy()
{
	DeleteObject(hRedBrush);
	DeleteObject(hNeonBlueBrush);
	DeleteObject(hNeonGreenBrush);
	DeleteObject(hNeonPinkBrush);
}

void Enemy::Update()
{
	if (!isActive) return;

	Move();
	Damaged();
	Fire();
}

void Enemy::Render(HDC hdc)
{
	if (!isActive) return;
	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
	Circle::Render(hdc);
	SelectObject(hdc, defaultBrush);
}

void Enemy::Spawn(Vector2 pos)
{
	center = pos;
	isDamaged = false;
	isActive = true;
	switch (phase)
	{
	case 0:
		hp = 30;
		hSelectBrush = hNeonBlueBrush;
		break;
	case 1:
		hp = 50;
		hSelectBrush = hNeonGreenBrush;
		break;
	case 2:
		hp = 80;
		hSelectBrush = hNeonPinkBrush;
		break;
	}
}

void Enemy::Move()
{
	center.y += SPEED * DELTA;
	if (center.y > SCREEN_HEIGHT)
	{
		isActive = false;
	}
}

void Enemy::Damaged()
{
	if (isDamaged)
	{
		damageTimer += DELTA;
		if (damageTimer >= DAMAGE_INTERVAL)
		{
			damageTimer = 0;
			isDamaged = false;
			switch (phase)
			{
			case 0: hSelectBrush = hNeonBlueBrush; break;
			case 1: hSelectBrush = hNeonGreenBrush; break;
			case 2: hSelectBrush = hNeonPinkBrush; break;
			}
		}
	}
	if (PlayerBulletManager::Get()->IsCollision(this))
	{
		hp -= 10;
		isDamaged = true;
		hSelectBrush = hRedBrush;
		if (hp <= 0)
		{
			isActive = false;
		}
	}
}

void Enemy::Fire()
{
	
}
