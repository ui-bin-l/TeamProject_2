#pragma once

class GameOverScene : public Scene
{
public:
	GameOverScene();
	~GameOverScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;
};