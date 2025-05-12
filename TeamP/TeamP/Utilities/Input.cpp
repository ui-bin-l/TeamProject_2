#include "Framework.h"

void Input::Update()
{
	memcpy(oldState, curState, sizeof(oldState));

	GetKeyboardState(curState);

	//0, 1 ->Ű���� �Է�X
	//128, 129->Ű���� �Է�O

	for (int i = 0; i < KEY_MAX; i++)
	{
		curState[i] = (curState[i] & 0x80) ? 1 : 0;

		BYTE old = oldState[i];
		BYTE cur = curState[i];

		if (old == 0 && cur == 1)
			mapState[i] = Down;
		else if (old == 1 && cur == 0)
			mapState[i] = Up;
		else if (old == 1 && cur == 1)
			mapState[i] = Press;
		else
			mapState[i] = None;
	}
}