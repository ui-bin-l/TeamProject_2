#pragma once

class BulletManager : public Singleton<BulletManager>
{
	friend class Singleton;

private:
	const int ENEMY_BULLET_POOL = 300;
private:
	BulletManager();
	~BulletManager();
public:
	void Update();
	void Render(HDC hdc);
	bool IsCollision(Circle* circle, string tag);

	void Fire(Vector2 pos, string tag, Vector2 direction = Vector2::Up());
private:
	vector<Bullet*> bullets;

};