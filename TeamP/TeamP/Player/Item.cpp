#include "Framework.h"
#include "Item.h"

Item::Item() :Circle(20)
{
	itemTag = End;
}

Item::~Item()
{
}

void Item::Spawn(Vector2 position)
{
	center = position;
	isActive = true;
	int randItem = rand() % (int)ItemType::End;
	itemTag = (ItemType)randItem;
}


