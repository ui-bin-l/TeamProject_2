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
	void Update();
	void Render(HDC hdc);

	bool IsCollision(Player* player);
	void RandomItem(Player* player);
	void ItemCreate(Vector2 pos);

private:
	vector<Item*> items;
};