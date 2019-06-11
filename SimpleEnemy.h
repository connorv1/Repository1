#pragma once

class SimpleEnemy :	public GameObject
{
public:
	SimpleEnemy();
	~SimpleEnemy();

	//modify existing function from base class
	void Move();
};

