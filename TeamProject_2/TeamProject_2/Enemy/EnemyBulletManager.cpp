#include "Framework.h"

EnemyBulletManager::EnemyBulletManager()
{
    bullets.resize(ENEMY_BULLET_POOL);
    for (Bullet*& bullet : bullets)
    {
        bullet = new Bullet;
        bullet->SetActive(false);
    }
}

EnemyBulletManager::~EnemyBulletManager()
{
    for (Bullet*& bullet : bullets)
    {
        delete bullet;
    }
    bullets.clear();
}

void EnemyBulletManager::Update()
{
    for (Bullet*& bullet : bullets)
    {
        bullet->Update();
    }
}

void EnemyBulletManager::Render(HDC hdc)
{
    for (Bullet*& bullet : bullets)
    {
        bullet->Render(hdc);
    }
}

bool EnemyBulletManager::IsCollision(Circle* circle, string tag)
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

void EnemyBulletManager::Fire(Vector2 pos, string tag, Vector2 direction)
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
