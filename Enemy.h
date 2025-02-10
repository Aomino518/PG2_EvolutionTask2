#pragma once
#include "Object.h"
#include "Score.h"

class Enemy : public Object
{
private:
	int respawnTimer;

public:
	Enemy();
	void Move(Vector2 bulletPos, float bulletRadius, Vector2 playerPos, float playerRadius, Score* score);
	void Draw();
	Vector2 GetterPos();
	float GetterRadius();
	int GetterIsActive();
};

