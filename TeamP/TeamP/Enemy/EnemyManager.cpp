#include "Framework.h"

EnemyManager::EnemyManager()
{
	enemies.resize(ENEMY_POOL_SIZE);
	for (Enemy*& enemy : enemies)
	{
		enemy = new NormalEnemy();
		enemy->SetActive(false);
	}
}

EnemyManager::~EnemyManager()
{
	for (Enemy*& enemy : enemies)
	{
		delete enemy;
	}
	enemies.clear();
}

void EnemyManager::Update()
{
	gameTimer += DELTA;
	spawnTimer += DELTA;
	phaseTimer += DELTA;
	if (phaseTimer >= 15.0f)
		phase = 3;
	else if (phaseTimer >= 10.0f)
		phase = 2;
	else if (phaseTimer >= 5.0f)
		phase = 1;
	else
		phase = 0;
	if (spawnTimer > SPAWN_INTERVAL)
	{
		spawnTimer = 0.0f;
		SpawnEnemy();
	}
	for (Enemy*& enemy : enemies)
	{
		enemy->SetPhase(phase);
		enemy->Update();
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (Enemy*& enemy : enemies)
	{
		enemy->Render(hdc);
	}
}
EnemyManager::EnemyType EnemyManager::GetCurrentEnemyType()
{
	if (gameTimer >= 15.0f)
	{
		return EnemyType::Boss;
	}
	else if (gameTimer >= 12.0f)
	{
		return EnemyType::Elite;
	}
	else if (gameTimer >= 10.0f)
	{
		return EnemyType::Elite;
	}
	else if (gameTimer >= 5.0f)
	{
		return EnemyType::Strong;
	}
	else
	{
		return EnemyType::Normal;
	}
}


void EnemyManager::SpawnEnemy()
{
	for (int i = 0; i < ENEMY_POOL_SIZE; ++i)
	{
		if (enemies[i] == nullptr || !enemies[i]->IsActive())
		{
			EnemyType type = GetCurrentEnemyType();
			if (type == EnemyType::Boss)
			{
				bool bossExists = false;
				for (Enemy* enemy : enemies)
				{
					if (enemy != nullptr && enemy->IsActive() && dynamic_cast<Boss*>(enemy) != nullptr)
					{
						bossExists = true;
						break;
					}
				}
				if (bossExists)
					return;
			}
			else
			{
				enemies[i]->SetActive(false);
			}
			if (enemies[i]) delete enemies[i];

			switch (type)
			{
			case EnemyType::Normal:
				enemies[i] = new NormalEnemy();
				break;
			case EnemyType::Strong:
				enemies[i] = new StrongEnemy();
				break;
			case EnemyType::Elite:
				enemies[i] = new EliteEnemy();
				break;
			case EnemyType::Boss:
				enemies[i] = new Boss();
				enemies[i]->SetRadius(60);
				enemies[i]->Spawn({ (float)(SCREEN_WIDTH / 2), 0.0f });
				break;
			}

			enemies[i]->SetPlayer(player);
			enemies[i]->SetPhase(phase);
			enemies[i]->Spawn({ (float)(rand() % SCREEN_WIDTH), 0.0f });
			break;
		}
	}
}

void EnemyManager::SetPlayer(Player* player)
{
	this->player = player;
	for (Enemy*& enemy : enemies)
	{
		enemy->SetPlayer(player);
	}
}
