#pragma once

class PlayerBulletManager : public Singleton<PlayerBulletManager>
{
	friend class Singleton;

private:
	const int PLAYER_BULLET_POOL = 300;
private:
	PlayerBulletManager();
	~PlayerBulletManager();
public:
	void Update();
	void Render(HDC hdc);
	bool IsCollision(Circle* circle, string tag);

	void Fire(Vector2 pos, string tag, Vector2 direction = Vector2::Up());
private:
	vector<Bullet*> bullets;

};