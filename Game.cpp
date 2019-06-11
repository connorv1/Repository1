#include "Main.h"


Game::Game()
{
	//initialize random generator
	srand(time(NULL));

	//load a background bitmap
	bg = al_load_bitmap("map.bmp");
	//load player and enemy bitmaps
	pbmp = al_load_bitmap("right.gif");
	player.SetShape(pbmp);
	player.frames[0] = al_load_bitmap("r0.gif");
	player.frames[1] = al_load_bitmap("r1.gif");
	player.frames[2] = al_load_bitmap("r2.gif");
	player.position.x = 100;
	player.position.y = 250;

	//enemies
	ebmp = al_load_bitmap("enemy.bmp");
	for (int i = 0; i < NUM_SIMPLE_ENEMIES; i++)
	{
		enemy1[i].SetShape(ebmp);
		enemy1[i].position.x = enemy1[i].position.y = 300;
		Vector2D v;
		v.x = rand() % 7 - 3;
		v.y = rand() % 7 - 3;
		enemy1[i].SetSpeed(v);
	}
	enemy2.SetShape(ebmp);
	enemy2.position.x = enemy2.position.y = 400;
	enemy2.target = &player;
	end = false;
	int effect = 2;

	physics.collisionMethod = CollisionMethod::InsideRect;
}
Game::~Game()
{
	//release/destroy anything we have allocated/created in this class
	al_destroy_bitmap(bg);
	al_destroy_bitmap(pbmp);
	al_destroy_bitmap(ebmp);
}
void Game::Run()
{
	//main loop
	while (!end)
	{
		Update();
		Draw();
		al_rest(0.1); //slower 
	}

}
void Game::Update()
{
	//read user input and update all variables

	al_get_keyboard_state(&key_state);

	//end program
	if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) //al_key_down checks the status of a key in the key_state structure
	{
		end = true;
	}
	//change player speed using arrow keys
	Vector2D v;
	v.x = v.y = 0;
	player.SetSpeed(v);
	player.SetShape(pbmp);
	if (al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
	{
		v.x = 10;
		player.SetSpeed(v);
		player.Advance();
	}
	if (al_key_down(&key_state, ALLEGRO_KEY_LEFT))
	{
		v.x = -10;
		player.SetSpeed(v);
		player.Advance();
	}
	//no vertical movement

	if (al_key_down(&key_state, ALLEGRO_KEY_SPACE)) {
		effect = rand() % 3;
	}

	//move objects
	physics.Move(&player);
	//loop for all enemies
	for (int i = 0; i < NUM_SIMPLE_ENEMIES; i++)
	{
		enemy1[i].Move();
		physics.Move(&enemy1[i]);
		//check collision
		if (physics.Collision(&enemy1[i], &player)) //pay attention to order. We are checking if corners of o1 are inside o2
			end = true; //end game
	}
	enemy2.Move();
	physics.Move(&enemy2);
}
void Game::Draw()
{
	//all drawing will be here

	//start by erasing frame
	//al_draw_bitmap(bg, 0, 0, 0);
	render.Begin(bg);

	//draw objects and other content (menus, etc)
	//player.Draw();
	//enemy1.Draw();
	//enemy2.Draw();
	render.Draw(&player, effect);
	//loop for all enemies
	for (int i = 0; i < NUM_SIMPLE_ENEMIES; i++)
		render.Draw(&enemy1[i], effect);
	render.Draw(&enemy2, effect);
	//put on primary buffer
	//al_flip_display();
	render.End();
}
