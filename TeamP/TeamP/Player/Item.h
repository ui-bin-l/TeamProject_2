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
	//void UpgradeSpeed(Player* player);
	//void UpgradeBulletSpeed(Player* player);
	//void UpgradeBulletPower(Player* player);
	//void AddBulletLine(Player* player);


private:
	ItemType itemTag;
	Player* player;
};