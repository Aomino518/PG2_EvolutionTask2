#include "Play.h"

Play::Play()
{
	isPlay = true;
	timeRimitTimer = 1800;
	player = new Player();
	enemy = new Enemy();
}

Play::~Play()
{
	delete player;
	delete enemy;
}

void Play::Update(char* keys, char* preKeys, Score* score)
{
	if (timeRimitTimer > 0) {
		timeRimitTimer--;
	}

	player->Move(keys, preKeys, enemy->GetterPos(), enemy->GetterRadius());
	enemy->Move(player->GetterBullet()->GetPos(), player->GetterBullet()->GetRadius(), player->GetterPos(), player->GetterRadius(), score);

	if (!player->GetterIsActive() || timeRimitTimer <= 0) {
		isPlay = false;
	}
}

void Play::Draw(int score)
{
	player->Draw();
	enemy->Draw();
	Novice::ScreenPrintf(640, 340, "TimeRimit:%d", timeRimitTimer / 60);
	Novice::ScreenPrintf(640, 360, "score:%d", score);
}

int Play::GetterIsPlay()
{
	return isPlay;
}

int Play::GetterTimerRimitTimer()
{
	return timeRimitTimer;
}

int Play::GetterPlayerIsActive()
{
	return player->GetterIsActive();
}
