#include "Framework.h"
#include "NormalEnemy.h"

void NormalEnemy::Fire()
{
	fireTimer += DELTA;
	if (fireTimer > FIRE_INTERVAL)
	{
		Vector2 direction = player->GetCenter() - center;
		EnemyBulletManager::Get()->Fire(center, direction);
		fireTimer = 0.0f;
	}
}
