#pragma once

class VictoryScene : public Scene
{
public:
	VictoryScene();
	~VictoryScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;
};