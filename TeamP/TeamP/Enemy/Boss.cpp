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
            // ���� �߻� ����
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
            // ���� �߻�

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
            // Ȯ�� �߻�
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
                float baseAngle = atan2(toPlayer.y, toPlayer.x); // �÷��̾� ���ϴ� ����

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
        // Y������ ��������
        center.y += SPEED * DELTA;

        // ��ǥ Y��ġ ���� �� ����
        if (center.y >= targetY)
        {
            center.y = targetY;
            reachedY = true;
        }
    }
    else
    {
        // X������ �¿� �̵�
        center.x += xDirection * xSpeed * DELTA;

        // ȭ�� ��� ���� �� ���� ����
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

    // ȭ�� ������ ������ ��� ��Ȱ��ȭ
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
        int patternChange = rand() % 4; // 0, 1, 2 �� �ϳ��� �������� ����
        bulletTimer = 0.0f; // ����
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
