#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet() {
	pos = { 0.0f, 0.0f };
	radius = 5.0f;
	speed = 8.0f;
	isActive = false;

}

void Bullet::Move() {
	if (isActive) {
		pos.y -= speed;

		if (pos.y <= 5.0f) {
			isActive = false;
		}
	}
}

void Bullet::Draw() {
	if (isActive) {
		Novice::DrawEllipse(
			static_cast<int>(pos.x),
			static_cast<int>(pos.y),
			static_cast<int>(radius),
			static_cast<int>(radius),
			0.0f,
			RED,
			kFillModeSolid
		);
	}
}

int Bullet::GetIsActive() {
	return isActive;
}

void Bullet::SetPos(Vector2 pos_) {
	pos = pos_;
}

void Bullet::SetIsActive(int isActive_) {
	isActive = isActive_;
}

Vector2 Bullet::GetPos()
{
	return pos;
}

float Bullet::GetRadius()
{
	return radius;
}
