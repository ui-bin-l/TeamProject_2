#pragma once

class Player;
class Item : public Circle
{
private:
	const float AddSpeed = 5.0f;
	const float AddBulletSpeed = 5.0f;
	const int AddBulletPower = 5;
	const int ITEM_TYPE_NUM = 4;

public:
	Item();
	~Item();
	ItemType GetItemTag() { return itemTag; }
	void Spawn(Vector2 position);
	void Render(HDC hdc);
	void ChangePen();


private:
	ItemType itemTag;

	HPEN hPen;
	HPEN changePen[4];
};