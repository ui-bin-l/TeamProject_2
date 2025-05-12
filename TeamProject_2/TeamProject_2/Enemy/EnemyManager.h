#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
	friend class Singleton;
private:
	const int ENEMY_POOL_SIZE = 50;
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
	vector<Enemy*> enemies;
	float spawnTimer = 0.0f;


};