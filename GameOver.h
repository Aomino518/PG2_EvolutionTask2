#pragma once
#include <Novice.h>

class GameOver
{
private:
	int isGameOver;

public:
	GameOver();
	~GameOver();
	void Move(char* keys, char* preKeys);
	void Draw(int score);
	int GetterIsGameOver();
};

