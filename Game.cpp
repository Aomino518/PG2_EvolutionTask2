#include "Game.h"

Game::Game()
{
	screenScene = TITLE;
	titleScene = new Title;
	playScene = nullptr;
	resultScene = nullptr;
	gameOverScene = nullptr;
	score_ = new Score();
}

Game::~Game()
{
}

void Game::Move(char* keys, char* preKeys)
{
	switch (screenScene) {
	case TITLE:

		if (titleScene != nullptr) {
			if (titleScene->GetterIsTitle()) {
				titleScene->Move(keys, preKeys);
			}
		}

		if (!titleScene->GetterIsTitle()) {
			delete titleScene;
			titleScene = nullptr;
			playScene = new Play();
			score_->SetterScore(0);
			screenScene = PLAY;
		}

		break;
	case PLAY:

		if (playScene != nullptr) {
			if (playScene->GetterIsPlay()) {
				playScene->Update(keys, preKeys, score_);
			}
		}

		if (!playScene->GetterIsPlay()) {
			if (playScene->GetterTimerRimitTimer() <= 0) {
				delete playScene;
				playScene = nullptr;
				resultScene = new Result();
				screenScene = RESULT;
			}
			else if (!playScene->GetterPlayerIsActive()) {
				delete playScene;
				playScene = nullptr;
				gameOverScene = new GameOver();
				screenScene = GAMEOVER;
			}
		}

		break;
	case RESULT:

		if (resultScene != nullptr) {
			if (resultScene->GetterIsResult()) {
				resultScene->Move(keys, preKeys);
			}
		}

		if (!resultScene->GetterIsResult()) {
			delete resultScene;
			resultScene = nullptr;
			titleScene = new Title();
			screenScene = TITLE;
		}

		break;
	case GAMEOVER:

		if (gameOverScene != nullptr) {
			if (gameOverScene->GetterIsGameOver()) {
				gameOverScene->Move(keys, preKeys);
			}
		}

		if (!gameOverScene->GetterIsGameOver()) {
			delete gameOverScene;
			gameOverScene = nullptr;
			titleScene = new Title();
			screenScene = TITLE;
		}

		break;
	}
}

void Game::Draw()
{
	switch (screenScene) {
	case TITLE:

		if (titleScene != nullptr) {
			titleScene->Draw();
		}

		break;
	case PLAY:

		if (playScene != nullptr) {
			playScene->Draw(score_->GetterScore());
		}

		break;
	case RESULT:
		
		if (resultScene != nullptr) {
			resultScene->Draw(score_->GetterScore());
		}

		break;
	case GAMEOVER:
		
		if (gameOverScene != nullptr) {
			gameOverScene->Draw(score_->GetterScore());
		}

		break;
	}
}
