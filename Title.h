#pragma once
#include <Novice.h>

class Title
{
private:
	int isTitle;

public:
	Title();
	~Title();
	void Move(char* keys, char* preKeys);
	void Draw();
	int GetterIsTitle();
};

