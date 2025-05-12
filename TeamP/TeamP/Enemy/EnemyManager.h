#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
	friend class Singleton;
private:
	const int ENEMY_POOL_SIZE = 3;
	const float SPAWN_INTERVAL = 2.0f;
private:
	EnemyManager();
	~EnemyManager();
public:
	void Update();
	void Render(HDC hdc);

	void SpawnEnemy();
	void SetPlayer(Player* player);
private:
	enum class EnemyType { Normal, Strong, Elite };
	EnemyType GetCurrentEnemyType();
	
	float spawnTimer = 0.0f;
	float gameTimer = 0.0f;
	float phaseTimer = 0.0f;
	int phase = 0;
	vector<Enemy*> enemies;
	Player* player = nullptr;
};