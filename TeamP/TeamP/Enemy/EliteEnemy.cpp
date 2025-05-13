#include "Framework.h"
#include "EliteEnemy.h"

void EliteEnemy::Fire()
{
	float stepAngle = PI * 2.0f / FIRE_COUNT;
	fireTimer += DELTA;
	if (fireTimer > FIRE_INTERVAL)
	{
		for (int i = 0; i < FIRE_COUNT; i++)
		{
			float angle = stepAngle * i;
			Vector2 direction(cos(angle), sin(angle));
			EnemyBulletManager::Get()->Fire(center, direction,RGB(255, 20, 147));
		}
		fireTimer = 0.0f;
	}
}
