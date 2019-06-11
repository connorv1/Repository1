#include "Main.h"


GameObject::GameObject()
{
	position.x = position.y = speed.x = speed.y = 0;
	shape = NULL; //NULL is default for non-initialized pointers (means false or 0)
}
GameObject::~GameObject()
{
	//release anything dynamically created by this object
}
void GameObject::Draw()
{
	if (shape != NULL) //make sure we have a bitmap to draw
		al_draw_bitmap(shape, position.x, position.y, 0);
}

void GameObject::Move()
{
	position.x += speed.x;
	position.y += speed.y;
}


void GameObject::SetShape(ALLEGRO_BITMAP* b)
{
	//make sure the bitmap is valid
	if (b != NULL)
		shape = b;
}
ALLEGRO_BITMAP* GameObject::GetShape()
{
	return shape;
}
void GameObject::SetSpeed(Vector2D s)
{
	speed.x = s.x;
	speed.y = s.y;
}

void GameObject::GetSpeed(Vector2D* ps)
{
	ps->x = speed.x;
	ps->y = speed.y;
}