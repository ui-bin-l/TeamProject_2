#pragma once

class Player;
class Item : public Circle
{
private:
	const float AddSpeed = 5.0f;
	const float AddBulletSpeed = 5.0f;
	const int AddBulletPower = 5;

public:
	Item();
	~Item();
	ItemType GetItemTag() { return itemTag; }
	void Spawn(Vector2 position);
	//void UpgradeSpeed(Player* player);
	//void UpgradeBulletSpeed(Player* player);
	//void UpgradeBulletPower(Player* player);
	//void AddBulletLine(Player* player);
	// 이거 다 Player에서 하면되겠다! 대박스 this로 넘기면되니까 랜덤으로 음음 좋아

private:
	ItemType itemTag;
};