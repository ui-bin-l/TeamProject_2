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

		//�ٿ� ĳ����
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
	float angleStep = 360.0f / 4; // �� �Ѿ� ���� ���� ����
	float degreeToRadian = 3.141592f / 180.0f;
	int fired = 0;
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			float angle = angleStep * fired; // ���� �Ѿ��� �߻� ����
			float radian = angle * degreeToRadian;

			Vector2 direction = Vector2(cosf(radian), sinf(radian));
			bullet->Fire(pos, direction); // ������ �����ؼ� �߻�
			fired++;

			if (fired >= 4)
				break;
		}
	}
}

void PlayerBulletManager::CircleFire(Vector2 pos)
{
	float angleStep = 360.0f / 12; // �� �Ѿ� ���� ���� ����
	float degreeToRadian = 3.141592f / 180.0f;

	int fired = 0;
	for (PlayerBullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			float angle = angleStep * fired; // ���� �Ѿ��� �߻� ����
			float radian = angle * degreeToRadian;

			Vector2 direction = Vector2(cosf(radian), sinf(radian));
			bullet->Fire(pos, direction); // ������ �����ؼ� �߻�
			fired++;

			if (fired >= 12)
				break;
		}
	}
}
