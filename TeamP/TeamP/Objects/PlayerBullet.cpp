#include "Framework.h"

PlayerBullet::PlayerBullet() : Circle(7)
{
	hBrush = CreateSolidBrush(RGB(0, 191, 255));
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

void PlayerBullet::Render(HDC hdc)
{
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Circle::Render(hdc);
	SelectObject(hdc, oldBrush);
}
