#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (size_t i = 0; i < ITEM_POOL_SIZE; ++i)
	{
		items[i] = new Item();
		items[i]->SetActive(false);  // 기본은 비활성 상태로 시작
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

void ItemManager::Update()
{
	spawnTime += DELTA;
	if (spawnTime > 3.0f)
	{
		spawnTime = 0.0f;

		for (Item* item : items)
		{
			if (!item->IsActive())
			{
				Vector2 spawnPos = { (float)(rand() % SCREEN_WIDTH), (float)(rand() % SCREEN_HEIGHT) };
				item->Spawn(spawnPos);
				break;
			}
		}
	}

	/*for (Item* item : items)
	{
		if (item->IsActive())
			item->Update();
	}*/
}


ItemType ItemManager::GetItem(Player* player)
{
	for (Item* item : items)
	{
		if (!item->IsCollisionCircle(player) || !item->IsActive())
			continue;
		item->SetActive(false);
		return item->GetItemTag();
	}
	return ItemType(End);
}




