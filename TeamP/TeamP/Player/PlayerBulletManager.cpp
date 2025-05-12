#include "Framework.h"

PlayerBulletManager::PlayerBulletManager()
{
    bullets.resize(PLAYER_BULLET_POOL);
    for (Bullet*& bullet : bullets)
    {
        bullet = new Bullet;
        bullet->SetActive(false);
    }
}

PlayerBulletManager::~PlayerBulletManager()
{
    for (Bullet*& bullet : bullets)
    {
        delete bullet;
    }
    bullets.clear();
}

void PlayerBulletManager::Update()
{
    for (Bullet*& bullet : bullets)
    {
        bullet->Update();
    }
}

void PlayerBulletManager::Render(HDC hdc)
{
    for (Bullet*& bullet : bullets)
    {
        bullet->Render(hdc);
    }
}

bool PlayerBulletManager::IsCollision(Circle* circle, string tag)
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

void PlayerBulletManager::Fire(Vector2 pos, string tag, Vector2 direction)
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
