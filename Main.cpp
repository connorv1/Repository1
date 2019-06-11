/*
Title: Assignment - M3
Author: Connor VanRumpt

Objective: Modify the BaseGame code so that when the space key is pressed, one of the three effects (flipvertical, fliphorizontal, and channel)
is applied to 10 game objects.

Classes:
Effect class contains 3 child classes (flipvertical, fliphorizontal, channel) and a  member function Apply
which applies the change to the specified BMP(s)

Game class contains member variables for GameObjects such as players and enemies,bitmaps for the gameobjects and background,
and member functions Run, Update, and Draw. Run begins the application loop, Update takes user key press and determines what to do,
and then Draw applies the appropriate changes

GameObject class contains a bitmap for the object shape, 2D member vectors for position and speed of the objects in the x,y directions.
It contains the member functions Move and Drawwhich update the GameObjects location. It also has setters for shape and speed,
and a getter for speed. Gameobject also has 3 child classes, AnimatedObject, SimpleEnemy and SmartEnemy

Render class contains 3 pointer member variables; flipV, flipH and chan. It has a Draw function which draws objects, a Begin function
which draws background, and an End function which moves to the primary buffer

Physics class contains a member variable collisionmethod, and a function Collision which determines which type of collision has occured.
There is also 3 functions, Collision1, Collision2, and Collision3 which each check for collisions using different methods.

*/


#include "Main.h"

//====================================================================
// Globals
//====================================================================

//global variable for display
ALLEGRO_DISPLAY* g_display = NULL; //ALLEGRO_DISPLAY is a "user defined type" in Allegro. * shows a pointer

//global variable for font
ALLEGRO_FONT *g_font;

//initialzie Allegro components
void InitAllegro(int screenWidth, int screenHeight)
{

	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	//initialize display screen
	g_display = al_create_display(screenWidth, screenHeight);
	if (!g_display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//initialize keyboard
	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n");
		exit(0);
	}

	//initialize image addon
	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon!\n");
		exit(0);
	}

	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}
	//initialize primitive shapes
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}
	//initialize font
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon	 (get fonts here: http://www.1001freefonts.com/)
	g_font = al_load_ttf_font("uchiyama.ttf", 12, 0); //secodn variable is size
	//g_font = al_load_font("a4_font.tga", 0, 0); //size variable doesn't matter becasue the font is fixed-size 
	if (!g_font)
	{
		printf("failed to create font!\n");
		exit(0);
	}
}

//End and clean up Allegro components
void EndAllegro()
{
	al_destroy_display(g_display);
}


//main function
void main()
{
	///////////////////////////////////
	// INITIALIZE
	///////////////////////////////////

	//initialize allegro
	int sw = 640;
	int sh = 480;
	InitAllegro(sw, sh);

	//create main object
	Game game;

	///////////////////////////////////
	// LOOP (includes update and draw)
	///////////////////////////////////

	game.Run();

	//clean up
	EndAllegro();
}