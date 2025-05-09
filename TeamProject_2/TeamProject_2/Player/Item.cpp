#include "Framework.h"
#include "Item.h"

Item::Item() :Circle(20)
{
}

Item::~Item()
{
}

void Item::Update()
{
	// 시간에 따라서 center조절하기? 변경안하고 처음 생성만 할거니까 괜찮을듯
}

void Item::ItemCreate(Vector2 pos)
{
	// 아이템 생성하기,,.? 근데 이건 객체 생성하면서 되는거아닌가? 그럼 그냥 render로 가야되는거아닌가..?
}


void Item::UpgradeSpeed(Player* player)
{
	player->SetSpeed(player->GetSpeed() + AddSpeed);
	wstring str = L"PLAYER 속도 UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::UpgradeBulletSpeed(Player* player)
{
	player->SetBulletSpeed(player->GetBulletSpeed() + AddBulletSpeed);
	wstring str = L"BULLET 속도 UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::UpgradeBulletPower(Player* player)
{
	player->SetBulletPower(player->GetBulletPower() + AddBulletPower);
	wstring str = L"BULLET 파워 UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::AddBulletLine(Player* player)
{
	wstring str = L"PLAYER 총 증가!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}
