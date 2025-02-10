#pragma once
#include <Novice.h>
#include "Enum.h"
#include "Title.h"
#include "Play.h"
#include "Result.h"
#include "GameOver.h"
#include "Score.h"

class Game
{
private:
	int screenScene;
	Title* titleScene;
	Play* playScene;
	Result* resultScene;
	GameOver* gameOverScene;
	Score* score_;

public:
	Game();
	~Game();
	void Move(char* keys, char* preKeys);
	void Draw();
};

