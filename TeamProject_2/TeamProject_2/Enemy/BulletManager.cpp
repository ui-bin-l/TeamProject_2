#include "Framework.h"

BulletManager::BulletManager()
{
    bullets.resize(ENEMY_BULLET_POOL);
    for (Bullet*& bullet : bullets)
    {
        bullet = new Bullet;
        bullet->SetActive(false);
    }
}

BulletManager::~BulletManager()
{
    for (Bullet*& bullet : bullets)
    {
        delete bullet;
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
        if (!bullet->IsActive())
            continue;
        if (!bullet->IsCollisionCircle(circle))
            continue;

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
            break;
        }
    }
}
