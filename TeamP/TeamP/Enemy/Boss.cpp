#include "Framework.h"

Boss::Boss()
{
	SetRadius(60);
}

Boss::~Boss()
{
}

void Boss::Fire()
{
    Vector2 directions[8] =
    {
    { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 },
    { 1, 1 }, { -1, 1 }, { -1, -1 }, { 1, -1 }
    };
    float minInterval = 0.1f;
    float fireInterval = max(minInterval, FIRE_INTERVAL - attackTimer * 0.01f);
    float stepAngle = PI * 2.0f / FIRE_COUNT;
    fireTimer += DELTA;
    attackTimer += DELTA;
    bulletSpeed = SPEED + attackTimer * 5.0f;
    if (fireTimer > fireInterval)
    {
        switch (attackPattern)
        {
        case PatternType::StraightBullet:
            // 직선 발사 예시
            if (fireTimer > fireInterval)
            {
                Vector2 direction = player->GetCenter() - center;
                Bullet* bullet = EnemyBulletManager::Get()->Fire(center, direction, RGB(0, 255, 255));
                if (bullet != nullptr)
                {
                    bullet->SetSpeed(bulletSpeed);
                }
                fireTimer = 0.0f;
            }
            break;

        case PatternType::CrossBullet:
            // 십자 발사

            if (fireTimer > fireInterval)
            {
                for (int i = 0; i < 8; i++)
                {
                    Vector2 dir = directions[i];
                    Bullet* bullet = EnemyBulletManager::Get()->Fire(center, dir, RGB(57, 255, 20));
                    if (bullet)
                    {
                        bullet->SetSpeed(bulletSpeed);
                    }
                }
                fireTimer = 0.0f;
            }
            break;

        case PatternType::SpreadBullet:
            // 확산 발사
            if (fireTimer > fireInterval)
            {
                for (int i = 0; i < FIRE_COUNT * 2; i++)
                {
                    float angle = stepAngle * i / 2;
                    Vector2 direction(cos(angle), sin(angle));
                    Bullet* bullet = EnemyBulletManager::Get()->Fire(center, direction, RGB(255, 20, 147));
                    if (bullet != nullptr)
                    {
                        bullet->SetSpeed(bulletSpeed);
                    }
                }
                fireTimer = 0.0f;
            }
        case PatternType::HalfCircleBullet:
        {
            if (fireTimer > fireInterval)
            {
                Vector2 toPlayer = player->GetCenter() - center;
                float baseAngle = atan2(toPlayer.y, toPlayer.x); // 플레이어 향하는 각도

                int halfFireCount = FIRE_COUNT / 2;
                float stepAngle = PI / (FIRE_COUNT * 1.5f);
                fireTimer += DELTA;
                if (fireTimer > FIRE_INTERVAL)
                {
                    for (int i = 0; i < halfFireCount; i++)
                    {
                        float angle = baseAngle + stepAngle * (i - (halfFireCount - 1) / 2.0f);
                        Vector2 direction(cos(angle), sin(angle));
                        Bullet* bullet = EnemyBulletManager::Get()->Fire(center, direction, RGB(57, 255, 20));
                        if (bullet != nullptr)
                        {
                            bullet->SetSpeed(bulletSpeed);
                        }
                    }

                    fireTimer = 0.0f;
                }
            }
        }
        }


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
        if (center.x <= radius)
        {
            center.x = radius;
            xDirection *= -1.0f;
        }
        else if (center.x >= SCREEN_WIDTH - radius)
        {
            center.x = SCREEN_WIDTH - radius;
            xDirection *= -1.0f;
        }
    }

    // 화면 밖으로 나가는 경우 비활성화
    if (center.x < -radius || center.x > SCREEN_WIDTH + radius)
    {
        isActive = false;
    }
}

void Boss::ChangePattern()
{
    bulletTimer += DELTA;
    if (bulletTimer > 5.0f)
    {
        int patternChange = rand() % 4; // 0, 1, 2 중 하나의 패턴으로 변경
        bulletTimer = 0.0f; // 리셋
        switch (patternChange)
        {
        case 0:
            attackPattern = PatternType::CrossBullet;
            break;
        case 1:
            attackPattern = PatternType::SpreadBullet;
            break;
        case 2:
            attackPattern = PatternType::StraightBullet;
            break;
        case 3:
            attackPattern = PatternType::HalfCircleBullet;
            break;
        }
    }
}

void Boss::Update()
{
    Move();
    Fire();
    ChangePattern();
    Damaged();
}
