#pragma once
#include <Novice.h>

class Result
{
private:
	int isResult;

public:
	Result();
	~Result();
	void Move(char* keys, char* preKeys);
	void Draw(int score);
	int GetterIsResult();
};

