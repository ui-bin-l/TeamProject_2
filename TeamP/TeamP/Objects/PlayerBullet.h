#pragma once

class PlayerBullet : public Circle
{
private:
	const float SPEED = 500;

public:
	PlayerBullet();
	~PlayerBullet();

	void Update();

	void Fire(Vector2 pos, Vector2 direction = Vector2::Up())
	{
		this->direction = direction.GetNormalized();
		isActive = true;
		center = pos;
	}

	void Render(HDC hdc);

private:
	Vector2 direction = Vector2::Up();
	HBRUSH hBrush;
};