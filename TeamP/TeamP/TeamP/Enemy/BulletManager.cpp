#include "Framework.h"

BulletManager::BulletManager()
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
	for (Bullet*& bullet : bullets)
	{
		bullet = new Bullet();
		bullet->SetActive(false);
	}
}

BulletManager::~BulletManager()
{
	for (Bullet*& bullet : bullets)
	{
		delete bullet;
		bullet = nullptr;
	}
	bullets.clear();
}

void BulletManager::Update()
{
	for (Bullet*& bullet : bullets)
	{
		bullet->Update();
	}
}

void BulletManager::Render(HDC hdc)
{

	for (Bullet*& bullet : bullets)
	{
		bullet->Render(hdc);
	}
}

bool BulletManager::IsCollision(Circle* circle, string tag)
{
	for (Bullet*& bullet : bullets)
	{
		if (bullet == nullptr)
			continue;
		if (!bullet->IsActive())
			continue;
		if (bullet->GetTag() != tag)
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

void BulletManager::Fire(Vector2 pos, string tag, Vector2 direction)
{
	for (Bullet*& bullet : bullets)
	{
		if (!bullet->IsActive())
		{

			bullet->Fire(pos, direction);
			bullet->SetTag(tag);
			break;
		}
	}
}
