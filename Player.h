#pragma once
#include "Object.h"
#include "Bullet.h"

class Player : public Object
{
private:
	Bullet* bullet;
public:
	Player();
	~Player();
	void Move(char* keys, char* preKeys, Vector2 enemyPos, float enemyRadius);
	void Draw();
	Bullet* GetterBullet();
	Vector2 GetterPos();
	float GetterRadius();
	int GetterIsActive();
};

