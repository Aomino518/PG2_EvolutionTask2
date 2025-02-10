#pragma once
#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Score.h"

class Play
{
private:
	int isPlay;
	int timeRimitTimer;
	Player* player;
	Enemy* enemy;
	
public:
	Play();
	~Play();
	void Update(char* keys, char* preKeys, Score* score);
	void Draw(int score);
	int GetterIsPlay();
	int GetterTimerRimitTimer();
	int GetterPlayerIsActive();
};

