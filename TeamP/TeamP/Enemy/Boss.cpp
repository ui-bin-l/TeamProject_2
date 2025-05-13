#include "Framework.h"

Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::Fire()
{
    float minInterval = 0.1f;
    float fireInterval = max(minInterval, FIRE_INTERVAL - bulletTimer * 0.05f);
    float stepAngle = PI * 2.0f / FIRE_COUNT;
    fireTimer += DELTA;
    bulletTimer += DELTA;
    if (fireTimer > fireInterval)
    {
        float bulletSpeed = SPEED + bulletTimer * 50.0f;
        for (int i = 0; i < FIRE_COUNT; i++)
        {
            float angle = stepAngle * i;
            Vector2 direction(cos(angle), sin(angle));
            Bullet* bullet = EnemyBulletManager::Get()->Fire(center, direction, RGB(255, 20, 147));
            if (bullet != nullptr)
            {
                bullet->SetSpeed(bulletSpeed);
            }
        }
        fireTimer = 0.0f;
    }
}

void Boss::Move()
{
    if (!reachedY)
    {
        // Y축으로 내려오기
        center.y += SPEED * DELTA;

        // 목표 Y위치 도달 시 멈춤
        if (center.y >= targetY)
        {
            center.y = targetY;
            reachedY = true;
        }
    }
    else
    {
        // X축으로 좌우 이동
        center.x += xDirection * xSpeed * DELTA;

        // 화면 경계 도달 시 방향 반전
        if (center.x <= radius || center.x >= SCREEN_WIDTH - radius)
        {
            xDirection *= -1.0f;
        }
    }

    // 화면 밖으로 나가는 경우 비활성화
    if (center.x < -radius || center.x > SCREEN_WIDTH + radius)
    {
        isActive = false;
    }
}