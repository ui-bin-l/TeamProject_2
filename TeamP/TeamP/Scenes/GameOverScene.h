#pragma once

class GameOverScene : public Scene
{
public:
	GameOverScene();
	~GameOverScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;
};