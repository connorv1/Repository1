#include "Main.h"


SimpleEnemy::SimpleEnemy()
{
	speed.x = speed.y = 1;
}


SimpleEnemy::~SimpleEnemy()
{
}

void SimpleEnemy::Move()
{
	if (position.x > 640 || position.x < 0)
		speed.x *= -1;
	if (position.y>480 || position.y < 0)
		speed.y *= -1;

	//actual move happens in Physics class
}
