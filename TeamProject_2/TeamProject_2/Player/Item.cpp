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
	// �ð��� ���� center�����ϱ�? ������ϰ� ó�� ������ �ҰŴϱ� ��������
}

void Item::ItemCreate(Vector2 pos)
{
	// ������ �����ϱ�,,.? �ٵ� �̰� ��ü �����ϸ鼭 �Ǵ°žƴѰ�? �׷� �׳� render�� ���ߵǴ°žƴѰ�..?
}


void Item::UpgradeSpeed(Player* player)
{
	player->SetSpeed(player->GetSpeed() + AddSpeed);
	wstring str = L"PLAYER �ӵ� UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::UpgradeBulletSpeed(Player* player)
{
	player->SetBulletSpeed(player->GetBulletSpeed() + AddBulletSpeed);
	wstring str = L"BULLET �ӵ� UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::UpgradeBulletPower(Player* player)
{
	player->SetBulletPower(player->GetBulletPower() + AddBulletPower);
	wstring str = L"BULLET �Ŀ� UP!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}

void Item::AddBulletLine(Player* player)
{
	wstring str = L"PLAYER �� ����!";
	TextOut(hdc, SCREEN_WIDTH >> 1, SCREEN_HEIGHT * 0.3f, str.c_str(), str.size());
}
