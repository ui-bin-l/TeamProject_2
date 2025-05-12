#include "Framework.h"
#include "ShootingScene.h"

ShootingScene::ShootingScene()
{
	player = new Player();

	EnemyBulletManager::Get();
	PlayerBulletManager::Get();
	EnemyManager::Get()->SetPlayer(player);
}

ShootingScene::~ShootingScene()
{
	delete player;

	EnemyBulletManager::Delete();
	PlayerBulletManager::Delete();
	EnemyManager::Delete();
}

void ShootingScene::Update()
{
	player->Update();

	EnemyBulletManager::Get()->Update();
	PlayerBulletManager::Get()->Update();
	EnemyManager::Get()->Update();
}

void ShootingScene::Render(HDC hdc)
{
	player->Render(hdc);
	EnemyBulletManager::Get()->Render(hdc);
	PlayerBulletManager::Get()->Render(hdc);
	EnemyManager::Get()->Render(hdc);
}
