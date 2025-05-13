#include "Framework.h"
#include "Item.h"

Item::Item() :Circle(15)
{
	itemTag = End;
	changePen[0] = CreatePen(PS_SOLID, 10, RGB(255, 114, 94));
	changePen[1] = CreatePen(PS_SOLID, 10, RGB(135, 206, 235));
	changePen[2] = CreatePen(PS_SOLID, 10, RGB(144, 238, 144));
	changePen[3] = CreatePen(PS_SOLID, 10, RGB(177, 156, 217));

	hPen = changePen[0];

}

Item::~Item()
{
	for (int i = 0; i < ITEM_TYPE_NUM; i++)
	{
		DeleteObject(changePen[i]);
	}
}

void Item::Spawn(Vector2 position)
{
	center = position;
	isActive = true;
	int randItem = rand() % (int)ItemType::End;
	itemTag = (ItemType)randItem;
	ChangePen();
}

void Item::Render(HDC hdc)
{
	if (!isActive) return;
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hPen);
	Circle::Render(hdc);
	SelectObject(hdc, oldBrush);
}

void Item::ChangePen()
{
	switch (itemTag)
	{
	case PlayerSpeed:
		hPen = changePen[0]; //오렌지
		break;
	case BulletSpeed:
		hPen = changePen[1]; //하늘색
		break;
	case BulletPower:
		hPen = changePen[2]; //라임그린
		break;
	case ChangeGun:
		hPen = changePen[3]; //보라색
		break;
	}
}


