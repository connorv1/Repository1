#include "Main.h"


SmartEnemy::SmartEnemy()
{
	target = NULL;
}


SmartEnemy::~SmartEnemy()
{
}

void SmartEnemy::Move()
{
	//determine speed (direction) based on target location
	speed.x = speed.y = 0;
	if (target != NULL)
	{
		if (position.x > target->position.x)
			speed.x = -1;
		if (position.x < target->position.x)
			speed.x = 1;
		if (position.y > target->position.y)
			speed.y = -1;
		if (position.y < target->position.y)
			speed.y = 1;
	}

	//actual move happens in Physics class
}
