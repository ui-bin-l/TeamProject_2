#include "Framework.h"

#include "Scenes/ShootingScene.h"

GameManager::GameManager()
{
	hdc = GetDC(hWnd);

	backBufferDC = CreateCompatibleDC(hdc);
	backBufferBitmap = CreateCompatibleBitmap(hdc, SCREEN_WIDTH, SCREEN_HEIGHT);
	SelectObject(backBufferDC, backBufferBitmap);

	Create();

	SCENE->AddScene("Title", new TitleScene());
	SCENE->AddScene("Game", new ShootingScene());
	SCENE->AddScene("Victory", new VictoryScene());
	SCENE->ChangeScene("Title");
}

GameManager::~GameManager()
{
	ReleaseDC(hWnd, hdc);
	Release();

	DeleteObject(backBufferBitmap);
	DeleteDC(backBufferDC);
}

void GameManager::Update()
{
	Timer::Get()->Update();
	Input::Get()->Update();

	SCENE->Update();

	InvalidateRect(hWnd, nullptr, false);
}

void GameManager::Render()
{
	PatBlt(backBufferDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, WHITENESS);

	SCENE->Render(backBufferDC);
	Timer::Get()->Render(backBufferDC);

	BitBlt(hdc,
		0, 0, SCREEN_WIDTH, SCREEN_HEIGHT,
		backBufferDC, 0, 0, SRCCOPY);
}

void GameManager::Create()
{
	Timer::Get();
	Input::Get();
	SceneManager::Get();
}

void GameManager::Release()
{
	Timer::Delete();
	Input::Delete();
	SceneManager::Delete();
}
