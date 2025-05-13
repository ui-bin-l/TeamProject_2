#include "Framework.h"
#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Update()
{
}

void GameOverScene::Render(HDC hdc)
{
	int x = SCREEN_WIDTH / 2 - 50;
	int y = SCREEN_HEIGHT / 2;
	TextOut(hdc, x, y - 40, L"Game Over", 9);
	TextOut(hdc, x, y + 0, L"    ____", 8);
	TextOut(hdc, x, y + 20, L"   /          |", 15);
	TextOut(hdc, x, y + 40, L"  | ( ; _ ; ) |", 15);
	TextOut(hdc, x, y + 60, L"   |    ^     /", 15);
	TextOut(hdc, x, y + 80, L"    -------", 11);

}