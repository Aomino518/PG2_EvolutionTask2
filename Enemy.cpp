#include "Enemy.h"
#include <Novice.h>
#include "Hit.h"
#include "Bullet.h"

Enemy::Enemy() {
	pos = { 640.0f, 50.0f };
	speed = 3.0f;
	radius = 15.0f;
	isActive = true;
	respawnTimer = 180;
}

void Enemy::Move(Vector2 bulletPos, float bulletRadius, Vector2 playerPos, float playerRadius, Score* score) {
	if (isActive) {
		pos.x += speed;

		if (pos.x <= 15.0f || pos.x >= 1265.0f) {
			speed *= -1;
		}

		if (Hit(pos, radius, bulletPos, bulletRadius) || Hit(pos, radius, playerPos, playerRadius)) {
			score->AddScore();
			isActive = false;
		}
	}
	else {
		respawnTimer--;
		if (respawnTimer <= 0) {
			isActive = true;
			respawnTimer = 180;
		}
	}
}

void Enemy::Draw() {
	if (isActive) {
		Novice::DrawEllipse(
			static_cast<int>(pos.x),
			static_cast<int>(pos.y),
			static_cast<int>(radius),
			static_cast<int>(radius),
			0.0f,
			BLACK,
			kFillModeSolid
		);
	}
}

Vector2 Enemy::GetterPos()
{
	return pos;
}

float Enemy::GetterRadius()
{
	return radius;
}

int Enemy::GetterIsActive()
{
	return isActive;
}
