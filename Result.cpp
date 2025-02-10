#include "Result.h"

Result::Result()
{
	isResult = true;
}

Result::~Result()
{
}

void Result::Move(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isResult = false;
	}
}

void Result::Draw(int score)
{
	Novice::ScreenPrintf(550, 360, "TIME UP");
	Novice::ScreenPrintf(550, 400, "score:%d", score);
	Novice::ScreenPrintf(550, 420, "Press SPECE to Title");
}

int Result::GetterIsResult()
{
	return isResult;
}
