#include "Framework.h"
#include "Player.h"

Player::Player() :Circle(30)
{
	center = { SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.9 };
	originalPen = CreatePen(PS_SOLID, PEN_WIDTH, RGB(250, 200, 130));
	damagePen = CreatePen(PS_SOLID, PEN_WIDTH, RGB(250, 100, 100));
}

Player::~Player()
{
	DeleteObject(originalPen);
	DeleteObject(damagePen);
}

void Player::Update()
{
	Move();
	pen = ChangePen();
	ItemGet();
	Render();
}

void Player::Render()
{
	DrawingPlayer();
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_LEFT) && center.x > 0)
	{
		center.x -= DELTA * speed;
	}
	else if (GetAsyncKeyState(VK_RIGHT) && center.x < SCREEN_WIDTH)
	{
		center.x += DELTA * speed;
	}
	else if (GetAsyncKeyState(VK_UP) && center.y > 0)
	{
		center.y -= DELTA * speed;
	}
	else if (GetAsyncKeyState(VK_DOWN) && center.y < SCREEN_HEIGHT)
	{
		center.y += DELTA * speed;
	}
}

void Player::DrawingPlayer()
{
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);
	Vector2 leftAndUp = { center.x - radius ,center.y - radius };
	Vector2 rightAndDown = { center.x + radius ,center.y + radius };

	MoveToEx(hdc, center.x, leftAndUp.y, nullptr);
	LineTo(hdc, leftAndUp.x, rightAndDown.y);

	MoveToEx(hdc, center.x, leftAndUp.y, nullptr);
	LineTo(hdc, rightAndDown.x, rightAndDown.y);

	MoveToEx(hdc, leftAndUp.x, rightAndDown.y, nullptr);
	LineTo(hdc, rightAndDown.x, rightAndDown.y);

	MoveToEx(hdc, center.x, rightAndDown.y, nullptr);
	LineTo(hdc, leftAndUp.x, center.y);

	MoveToEx(hdc, center.x, rightAndDown.y, nullptr);
	LineTo(hdc, rightAndDown.x, center.y);

	MoveToEx(hdc, leftAndUp.x, center.y, nullptr);
	LineTo(hdc, rightAndDown.x, center.y);

	SelectObject(hdc, oldPen);

}

HPEN Player::ChangePen()
{
	// �̰� �Ѿ� ������� damagePen���� �����ϰ��ϴ°� if (IsCollisionCircle()) return damagePen; 
	return originalPen;
}

void Player::Fire()
{
	//�ѽ�� ����
}

void Player::SpecialFire()
{
	if (GetAsyncKeyState('Q') && spacialGauge == MAX_SPACIAL_GAUGE)
	{
		// bulletmanager���� �Ͻ������� ������ ���� �����ұ� �� ������? �ƴϸ� ��û ū �Ѿ�?
		spacialGauge = 0;
	}
}

void Player::ItemGet()
{
	if (ItemManager::Get()->IsCollision(this))
	{
		ItemManager::Get()->RandomItem(this);
	}
}
