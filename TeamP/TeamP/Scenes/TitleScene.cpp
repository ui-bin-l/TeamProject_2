#include "Framework.h"
#include "TitleScene.h"

TitleScene::TitleScene()
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Update()
{
	if (Input::Get()->IsKeyDown(VK_F1))
	{
		SCENE->ChangeScene("Game");
	}
}

void TitleScene::Render(HDC hdc)
{
	TextOut(hdc, 230, 300, L"Press F1 to Start Game", 22);
}
