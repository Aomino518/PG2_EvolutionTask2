#include "Hit.h"
#include <math.h>

int Hit(Vector2 pos_A, float radius_A, Vector2 pos_B, float radius_B)
{
	float posAtoPosBX = pos_A.x - pos_B.x;
	float posAtoPosBY = pos_A.y - pos_B.y;
	float distance = sqrtf(posAtoPosBX * posAtoPosBX + posAtoPosBY * posAtoPosBY);

	if (distance <= radius_A + radius_B) {
		return 1;
	}

	return 0;
}
