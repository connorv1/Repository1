//this is a non-standard but widely supported way to make sure this file is included only once in compile
//header files can be included more than once and cause error
#pragma once

//another methods is using #define, #ifdef and #endif
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H //see #endif at the end


struct Vector2D //a 2D value  corresponding to X and Y dimensions (position, size, direction, etc)
{
	int x;
	int y;
};

class GameObject
{
	//private: is default
	//to prevent program from crashing, we want to make sure that bmp is always valid
	//we make it private so it can be changed only by calling SetBitmap function and there we check the bitmap to be valid
	//even child classes can't directly change bmp to avoid mistakes
	ALLEGRO_BITMAP* shape; //a pointer to bitmap
protected: 
	Vector2D speed; 
public:
	Vector2D position;

    //common practice is to implement functions outside the class
	GameObject();    //constructor
	~GameObject();   //destructor
	void Draw();
	void Move();
	//for accessing non-public members
	void SetShape(ALLEGRO_BITMAP* b);
	ALLEGRO_BITMAP* GetShape(); //to get the value
	void SetSpeed(Vector2D s);
	void GetSpeed(Vector2D* ps); //get data using pointers (or return a Vector2D)
	//using pointers you can return multiple values
};

#endif //GAMEOBJECT_H