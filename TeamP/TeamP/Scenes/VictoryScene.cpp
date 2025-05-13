#include "Framework.h"
#include "VictoryScene.h"

VictoryScene::VictoryScene()
{
}

VictoryScene::~VictoryScene()
{
}

void VictoryScene::Update()
{
}

void VictoryScene::Render(HDC hdc)
{
	TextOut(hdc, SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2, L"You Win", 7);

}
