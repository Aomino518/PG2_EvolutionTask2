#include "GameOver.h"

GameOver::GameOver()
{
	isGameOver = true;
}

GameOver::~GameOver()
{
}

void GameOver::Move(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		isGameOver = false;
	}
}

void GameOver::Draw(int score)
{
	Novice::ScreenPrintf(550, 360, "GAME OVER");
	Novice::ScreenPrintf(550, 380, "score:%d", score);
	Novice::ScreenPrintf(550, 400, "Press SPACE to Title");
}

int GameOver::GetterIsGameOver()
{
	return isGameOver;
}
