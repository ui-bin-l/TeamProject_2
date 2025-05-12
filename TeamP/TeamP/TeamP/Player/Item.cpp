#include "Framework.h"

Item::Item() :Circle(20)
{
	ItemType end = End;
	int randItem = rand() % (int)end;
	itemTag = (ItemType)randItem;

	center.x = rand() % SCREEN_WIDTH;
	center.y = rand() % SCREEN_HEIGHT;
}

Item::~Item()
{
}


