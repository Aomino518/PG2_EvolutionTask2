#include "Score.h"

Score::Score()
{
	score = 0;
}

void Score::AddScore()
{
	score += 100;
}

void Score::Draw()
{
	Novice::ScreenPrintf(550, 400, "score:%d", score);
}

int Score::GetterScore()
{
	return score;
}

void Score::SetterScore(int score_)
{
	score = score_;
}
