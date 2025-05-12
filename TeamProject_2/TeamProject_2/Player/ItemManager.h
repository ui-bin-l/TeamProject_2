#pragma once

class ItemManager : public Singleton<ItemManager>
{
	friend class Singleton;

private:
	const int ITEM_POOL_SIZE = 10;

private:
	ItemManager();
	~ItemManager();

public:
	void Render(HDC hdc);

	bool IsCollision(Player* player);
	ItemType GetItem(Player* player);

private:
	vector<Item*> items;
};