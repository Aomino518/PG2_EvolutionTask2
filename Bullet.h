#pragma once
#include "Object.h"

class Bullet : protected Object
{
public:
	Bullet();
	void Move();
	void Draw();
	int GetIsActive();
	void SetPos(Vector2 pos_);
	void SetIsActive(int isActive_);
	Vector2 GetPos();
	float GetRadius();
};

