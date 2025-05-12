#include "Framework.h"

void StrongEnemy::Fire()
{
	// 플레이어 방향 벡터 구함
	Vector2 toPlayer = player->GetCenter() - center;
	float baseAngle = atan2(toPlayer.y, toPlayer.x); // 플레이어 향하는 각도

	int halfFireCount = FIRE_COUNT / 2;
	float stepAngle = PI * 2.0f / FIRE_COUNT;
	fireTimer += DELTA;
	if (fireTimer > FIRE_INTERVAL)
	{
		for (int i = 0; i < halfFireCount; i++)
		{
			float angle = baseAngle + stepAngle * (i - (halfFireCount - 1) / 2.0f);
			Vector2 direction(cos(angle), sin(angle));
			EnemyBulletManager::Get()->Fire(center, direction);
		}
		fireTimer = 0.0f;
	}
}
