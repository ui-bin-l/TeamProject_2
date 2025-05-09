#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (Item* item : items)
	{
		item = new Item();
		item->SetActive(false);
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

void ItemManager::Update()
{
	for (Item* item : items)
		item->Update();
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

void ItemManager::RandomItem(Player* player)
{
	for (Item* item : items)
	{
		if (!item->IsActive())
			continue;
		int randomNum = rand() % 4;
		switch (randomNum)
		{
		case 0:
		{
			item->UpgradeSpeed(player);
		}
		break;
		case 1:
		{
			item->UpgradeBulletSpeed(player);
		}
		break;
		case 2:
		{
			item->UpgradeBulletPower(player);
		}
		break;
		case 3:
		{
			item->AddBulletLine(player);
		}
		break;
		}

	}
}

