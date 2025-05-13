#pragma once

class EnemyBulletManager : public Singleton<EnemyBulletManager>
{
	friend class Singleton;

private:
	const int ENEMY_BULLET_POOL = 300;
private:
	EnemyBulletManager();
	~EnemyBulletManager();
public:
	void Update();
	void Render(HDC hdc);
	bool IsCollision(Circle* circle);
	Bullet* Fire(Vector2 pos, Vector2 direction = Vector2::Up(), COLORREF color = RGB(255, 255, 255));
private:
	vector<Bullet*> bullets;

};