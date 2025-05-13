#pragma once

class Bullet : public Circle
{
private:
	float SPEED = 500;
	COLORREF color = RGB(255, 255, 255);
public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);
	void Fire(Vector2 pos, Vector2 direction = Vector2::Up(), COLORREF color = RGB(255, 255, 255))
	{
		this->direction = direction.GetNormalized();
		this->color = color;
		isActive = true;
		center = pos;
	}

	string GetTag() { return tag; }
	void SetTag(string tag) { this->tag = tag; }

	float GetSpeed() { return SPEED; }
	void SetSpeed(float speed) { this->SPEED = speed; }

private:
	string tag;
	Vector2 direction = Vector2::Up();
};