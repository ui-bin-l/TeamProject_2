#include "Framework.h"

PlayerBullet::PlayerBullet() : Circle(5)
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update()
{
	center += direction * SPEED * DELTA;

	if (center.y < 0 || center.x < 0 || center.y > SCREEN_HEIGHT || center.x > SCREEN_WIDTH)
	{
		isActive = false;
	}
}
