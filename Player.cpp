#include "Player.h"
#include <Novice.h>
#include "Hit.h"

Player::Player() {
	pos = { 640.0f, 650.0f };
	speed = 6.0f;
	radius = 20.0f;
	isActive = true;
	bullet = new Bullet();
}

Player::~Player() {
	if (bullet != nullptr) {
		delete bullet;
		bullet = nullptr;
	}
}

void Player::Move(char* keys, char* preKeys, Vector2 enemyPos, float enemyRadius) {
	if (keys[DIK_W]) {
		pos.y -= speed;
	}

	if (keys[DIK_A]) {
		pos.x -= speed;
	}

	if (keys[DIK_S]) {
		pos.y += speed;
	}

	if (keys[DIK_D]) {
		pos.x += speed;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (bullet != nullptr && !bullet->GetIsActive()) {
			bullet->SetPos(pos);
			bullet->SetIsActive(true);
		}
	}

	if (Hit(pos, radius, enemyPos, enemyRadius)) {
		isActive = false;
	}

	if (bullet != nullptr) {
		bullet->Move();
	}
}

void Player::Draw() {
	bullet->Draw();
	if (isActive) {
		Novice::DrawEllipse(
			static_cast<int>(pos.x),
			static_cast<int>(pos.y),
			static_cast<int>(radius),
			static_cast<int>(radius),
			0.0f,
			WHITE,
			kFillModeSolid
		);
	}
}

Bullet* Player::GetterBullet()
{
	return bullet;
}

Vector2 Player::GetterPos()
{
	return pos;
}

float Player::GetterRadius()
{
	return radius;
}

int Player::GetterIsActive()
{
	return isActive;
}
