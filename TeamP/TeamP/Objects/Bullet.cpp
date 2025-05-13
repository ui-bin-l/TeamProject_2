#include "Framework.h"

Bullet::Bullet() : Circle(5)
{
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	center += direction * SPEED * DELTA;

	if (center.y < 0 || center.y > SCREEN_HEIGHT || center.x < 0 || center.x > SCREEN_WIDTH)
	{
		isActive = false;
	}
}

void Bullet::Render(HDC hdc)
{
	if (!isActive) return;

	HBRUSH brush = CreateSolidBrush(color);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
}
