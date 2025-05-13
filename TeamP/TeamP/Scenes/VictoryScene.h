#pragma once

class VictoryScene : public Scene
{
public:
	VictoryScene();
	~VictoryScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;
};