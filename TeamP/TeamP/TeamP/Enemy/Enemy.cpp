#include "Framework.h"

Enemy::Enemy() : Circle(30)
{
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	hSelectBrush = hBlueBrush;
}

Enemy::~Enemy()
{
	DeleteObject(hRedBrush);
	DeleteObject(hBlueBrush);

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
	hp = MAX_HP;
	isDamaged = false;
	hSelectBrush = hBlueBrush;
	isActive = true;
}

void Enemy::Move()
{
	center.y += DELTA;
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
			hSelectBrush = hBlueBrush;
		}
	}
	if (BulletManager::Get()->IsCollision(this, "player"))
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

	phaseTimer += DELTA;
	fireTimer += DELTA;
	float stepAngle = PI * 2.0f / FIRE_COUNT;
	if (fireTimer >= FIRE_INTERVAL)
	{
		fireTimer = 0.0f;
		if (phaseTimer < 5.0f)
		{
			Vector2 direction = player->GetCenter() - center;
			BulletManager::Get()->Fire(center, "Enemy", direction);
		}
		if (phaseTimer < 30.0f && phaseTimer >= 5.0f)
		{
			// 플레이어 방향 벡터 구함
			Vector2 toPlayer = player->GetCenter() - center;
			float baseAngle = atan2(toPlayer.y, toPlayer.x); // 플레이어 향하는 각도

			int halfFireCount = FIRE_COUNT / 2;
			float stepAngle = PI * 2.0f / FIRE_COUNT;
			for (int i = 0; i < halfFireCount; i++)
			{
				float angle = baseAngle + stepAngle * (i - (halfFireCount - 1) / 2.0f);
				Vector2 direction(cos(angle), sin(angle));
				BulletManager::Get()->Fire(center, "Enemy", direction);
			}
		}
		if (phaseTimer < 60.0f && phaseTimer >= 30.0f)
		{
			for (int i = 0; i < FIRE_COUNT; i++)
			{
				float angle = stepAngle * i;
				Vector2 direction(cos(angle), sin(angle));
				BulletManager::Get()->Fire(center, "Enemy", direction);
			}
		}

	}
}
