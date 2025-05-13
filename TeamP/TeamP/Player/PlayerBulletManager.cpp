#include "Framework.h"
#include "PlayerBulletManager.h"

PlayerBulletManager::PlayerBulletManager()
{
	//bullet = new Bullet();	

	//Reserve
	//bullets.reserve(BULLET_POOL_SIZE);
	//for (int i = 0; i < BULLET_POOL_SIZE; i++)
	//{
	//	Bullet* bullet = new Bullet();
	//	bullets.push_back(bullet);
	//}
	//Resize
	bullets.resize(BULLET_POOL_SIZE);//Bullet* bullets[50];
	for (PlayerBullet*& bullet : bullets)
	{
		bullet = new PlayerBullet();
		bullet->SetActive(false);
	}
}

PlayerBulletManager::~PlayerBulletManager()
{
	for (PlayerBullet*& bullet : bullets)
	{
		delete bullet;
	}
	bullets.clear();
}

void PlayerBulletManager::Update()
{
	for (PlayerBullet*& bullet : bullets)
	{
		bullet->Update();
	}
}

void PlayerBulletManager::Render(HDC hdc)
{
	//bullet->Render(hdc);
	for (PlayerBullet*& bullet : bullets)
	{
		bullet->Render(hdc);
	}
}

bool PlayerBulletManager::IsCollision(Circle* circle)
{
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
			continue;
		if (!bullet->IsCollisionCircle(circle))
			continue;

		//다운 캐스팅
			//Enemy* enemy = (Enemy*)(circle);
			//enemy->Damage();

		bullet->SetActive(false);
		return true;
	}

	return false;
}

void PlayerBulletManager::Fire(Vector2 pos)
{
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->Fire(pos);
			break;
		}
	}
}

void PlayerBulletManager::DownFire(Vector2 pos)
{
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			Vector2 direction = Vector2::Down();
			bullet->Fire(pos, direction);
			break;
		}
	}
}

void PlayerBulletManager::CrossFire(Vector2 pos)
{
	bulletCount = 4; // 발사할 총알 수
	float angleStep = FULL_ANGLE / bulletCount; // 각 총알 간의 각도 차이
	float degreeToRadian = PI / HALF_ANGLE;

	int fired = 0;
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			float angle = angleStep * fired;
			float radian = angle * degreeToRadian;

			Vector2 direction(cosf(radian), sinf(radian));
			bullet->Fire(pos, direction);
			fired++;

			if (fired >= bulletCount)
				break;
		}
	}
}

void PlayerBulletManager::CircleFire(Vector2 pos)
{
	bulletCount = 12;
	float angleStep = FULL_ANGLE / bulletCount; // 각 총알 간의 각도 차이
	float degreeToRadian = PI / HALF_ANGLE;

	int fired = 0;
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			float angle = angleStep * fired; // 현재 총알의 발사 각도
			float radian = angle * degreeToRadian;

			Vector2 direction = Vector2(cosf(radian), sinf(radian));
			bullet->Fire(pos, direction); // 방향을 지정해서 발사
			fired++;

			if (fired >= bulletCount)
				break;
		}
	}
}

void PlayerBulletManager::CrazyFire(Vector2 pos)
{
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			float randomAngle = ((float)rand() / RAND_MAX) * PI;
			Vector2 direction = { cosf(randomAngle),sinf(randomAngle) };
			bullet->Fire(pos, direction);
			break;
		}
	}
}

void PlayerBulletManager::ShotGunFire(Vector2 pos)
{
	bulletCount = 6;
	float angleStep = HALF_ANGLE / bulletCount; // 각 총알 간의 각도 차이
	float degreeToRadian = PI / HALF_ANGLE;

	int fired = 1;
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			float angle = angleStep * fired; // 현재 총알의 발사 각도
			float radian = -angle * degreeToRadian;

			Vector2 direction = Vector2(cosf(radian), sinf(radian));
			bullet->Fire(pos, direction); // 방향을 지정해서 발사
			fired++;

			if (fired >= bulletCount)
				break;
		}
	}
}
