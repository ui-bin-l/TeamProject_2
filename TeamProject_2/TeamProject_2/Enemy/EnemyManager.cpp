#include "Framework.h"

EnemyManger::EnemyManger()
{
	enemies.resize(ENEMY_POOL_SIZE);
	for (Enemy*& enemy : enemies)
	{
		enemy = new Enemy();
		enemy->SetActive(false);
	}
}

EnemyManger::~EnemyManger()
{
	for (Enemy*& enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
}

void EnemyManger::Update()
{
	spawnTimer += DELTA;
	if (spawnTimer > SPAWN_INTERVAL)
	{
		spawnTimer = 0.0f;
		SpawnEnemy();
	}
	for (Enemy*& enemy : enemies)
	{
		enemy->Update();
	}
}

void EnemyManger::Render(HDC hdc)
{
	for (Enemy*& enemy : enemies)
	{
		enemy->Render(hdc);
	}
}

void EnemyManger::SpawnEnemy()
{
	float spawnX = rand() % SCREEN_WIDTH;
	for (Enemy*& enemy : enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn({ (float)spawnX, 0 });
			break;
		}
	}
}

void EnemyManger::SetPlayer(Player* player)
{
	for (Enemy*& enemy : enemies)
	{
		enemy->SetPlayer(player);
	}
}
