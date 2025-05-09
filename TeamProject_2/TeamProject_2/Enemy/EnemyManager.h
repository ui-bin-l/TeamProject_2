#pragma once

class EnemyManger : public Singleton<EnemyManger>
{
	friend class Singleton;
private:
	const int ENEMY_POOL_SIZE = 50;
	const float SPAWN_INTERVAL = 2.0f;
private:
	EnemyManger();
	~EnemyManger();
public:
	void Update();
	void Render(HDC hdc);

	void SpawnEnemy();
	void SetPlayer(Player* player);
private:
	vector<Enemy*> enemies;
	float spawnTimer = 0.0f;


};