#include "Title.h"

Title::Title()
{
	isTitle = true;
}

Title::~Title()
{
}

void Title::Move(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isTitle = false;
	}
}

void Title::Draw()
{
	Novice::ScreenPrintf(500, 360, "Press Space to Start");
}

int Title::GetterIsTitle()
{
	return isTitle;
}
