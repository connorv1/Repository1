#include "Main.h"

//Global functions used by Collision

//simple structure with info for a rectangle
struct Rect
{
	int x;
	int y;
	int w;
	int h;
};
//calculte distance between two points
float Distance(int x1, int y1, int x2, int y2)
{
	float d = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	//needs math.h 
	d = sqrt(d);
	return d;
}
//check if a point is inside a rectangle
bool InRect(int x, int y, Rect r)
{
	if (x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h)
		return true;
	else
		return false;
}

Physics::Physics()
{
	collisionMethod = CollisionMethod::TopLeft;
}


Physics::~Physics()
{
}

bool Physics::Collision(GameObject* o1, GameObject* o2)
{
	switch (collisionMethod)
	{
	case CollisionMethod::TopLeft:
		return Collision1(o1, o2);
		break;  //break is not really necessary here as we are returning
	case CollisionMethod::Centre:
		return Collision2(o1, o2);
		break;  //break is not really necessary here as we are returning
	case CollisionMethod::InsideRect:
		return Collision3(o1, o2);
		break;  //break is not really necessary here as we are returning
	default:
		return false;
		break; //break is not really necessary here as we are returning
	}
}

bool Physics::Collision1(GameObject* o1, GameObject* o2)
{
	//method 1 (using top-right of the objects)
	int x1 = o1->position.x;
	int y1 = o1->position.y;
	int x2 = o2->position.x;
	int y2 = o2->position.y;
	float d = Distance(x1, y1, x2, y2);
	if (d < 10) //or use another value
		return true;
	else
		return false;
}
bool Physics::Collision2(GameObject* o1, GameObject* o2)
{
	//method 2 (using centre of the objects)
	int w1 = al_get_bitmap_width(o1->GetShape());
	int h1 = al_get_bitmap_height(o1->GetShape());
	int w2 = al_get_bitmap_width(o2->GetShape());
	int h2 = al_get_bitmap_height(o2->GetShape());
	int x1 = o1->position.x + w1 / 2;
	int y1 = o1->position.y + h1 / 2;
	int x2 = o2->position.x + w2 / 2;
	int y2 = o2->position.y + h2 / 2;
	float d = Distance(x1, y1, x2, y2);
	if (d < 10) //or use another value
		return true;
	else
		return false;
}
bool Physics::Collision3(GameObject* o1, GameObject* o2)
{
	//method 3 (check if one is inside the other)
	int w1 = al_get_bitmap_width(o1->GetShape());
	int h1 = al_get_bitmap_height(o1->GetShape());
	int w2 = al_get_bitmap_width(o2->GetShape());
	int h2 = al_get_bitmap_height(o2->GetShape());
	Rect r;
	r.x = o2->position.x;
	r.y = o2->position.y;
	r.w = w2;
	r.h = h2;
	bool in_TopLeft = InRect(o1->position.x, o1->position.y, r);
	bool in_TopRight = InRect(o1->position.x + w1 - 1, o1->position.y, r);
	bool in_BottomLeft = InRect(o1->position.x, o1->position.y + h1 - 1, r);
	bool in_BottomRight = InRect(o1->position.x + w1 - 1, o1->position.y + h1 - 1, r);

	if (in_TopLeft || in_TopRight || in_BottomLeft || in_BottomRight)
		return true;
	else
		return false;
}

void Physics::Move(GameObject* obj)
{
	//get object speed
	Vector2D s;
	obj->GetSpeed(&s);
	//move object
	obj->position.x += s.x;
	obj->position.y += s.y;
}