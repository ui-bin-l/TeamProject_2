#pragma once


class PlayerBulletManager : public Singleton<PlayerBulletManager>
{
	friend class Singleton;

private:
	const int BULLET_POOL_SIZE = 100;

private:
	PlayerBulletManager();
	~PlayerBulletManager();

public:
	void Update();
	void Render(HDC hdc);

	bool IsCollision(Circle* circle);

	void Fire(Vector2 pos);
	void DownFire(Vector2 pos);
	void CrossFire(Vector2 pos);
	void CircleFire(Vector2 pos);
	void CrazyFire(Vector2 pos);
	void ShotGunFire(Vector2 pos);


private:
	int bulletCount = 0;

	vector<PlayerBullet*> bullets;
};