#pragma once

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();

	// Scene��(��) ���� ��ӵ�
	void Update() override;
	void Render(HDC hdc) override;
};