#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN 

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 800

#define PI 3.141592f

#define DELTA Timer::Get()->GetElapsedTime()

#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
#include "Utilities/Singleton.h"
#include "Utilities/Timer.h"
#include "Utilities/Vector2.h"
#include "Utilities/Enum.h"

#include "Objects/Circle.h"
#include "Objects/Bullet.h"
#include "Enemy/BulletManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Enemy/EnemyManager.h"

#include "Player/Item.h"

#include "Scenes/Scene.h"
#include "Scenes/ShootingScene.h"
#include "Utilities/GameManager.h"
#include "Player/ItemManager.h"

extern HWND hWnd;
extern Vector2 mousePos;