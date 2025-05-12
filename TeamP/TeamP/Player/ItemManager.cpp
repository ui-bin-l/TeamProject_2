#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (Item* item : items)
	{
		item = new Item();
		item->SetActive(true);
	}
}

ItemManager::~ItemManager()
{
	for (Item* item : items)
	{
		delete item;
	}
	items.clear();
}


void ItemManager::Render(HDC hdc)
{
	for (Item* item : items)
		item->Render(hdc);
}

bool ItemManager::IsCollision(Player* player)
{
	for (Item* item : items)
	{
		if (!item->IsCollisionCircle(player) || !item->IsActive())
			continue;
		return true;
	}
	return false;
}

ItemType ItemManager::GetItem(Player* player)
{
	for (Item* item : items)
	{
		if (IsCollision(player))
			return item->GetItemTag();
	}
	return ItemType(End);
}




