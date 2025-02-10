#pragma once
#include <Novice.h>

class Score
{
private:
	int score;

public:
	Score();
	void AddScore();
	void Draw();
	int GetterScore();
	void SetterScore(int score_);
};

