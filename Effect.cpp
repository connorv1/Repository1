#include "Main.h"

Effect::Effect() {}

Effect::~Effect() {}

void Effect::Apply(ALLEGRO_BITMAP* img) {
}

FlipVertical::FlipVertical() {}

void FlipVertical::Apply(ALLEGRO_BITMAP * img)
{
	al_lock_bitmap(img, al_get_bitmap_format(img), ALLEGRO_LOCK_READWRITE);
	ALLEGRO_BITMAP* bmp = al_get_target_bitmap();

	al_set_target_bitmap(img);

	int w = al_get_bitmap_width(img);
	int h = al_get_bitmap_height(img);

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h / 2; j++)
		{
			//read colour value of 2 pixels
			ALLEGRO_COLOR c1 = al_get_pixel(img, i, j);
			ALLEGRO_COLOR c2 = al_get_pixel(img, i, h - 1 - j); //if a pixel is at j, its opposie is h-1-j
																//write at opposite locations
			al_put_pixel(i, j, c2);
			al_put_pixel(i, h - 1 - j, c1);
		}
	}
	al_unlock_bitmap(img);
	al_set_target_bitmap(bmp);
}

FlipVertical::~FlipVertical() {}

FlipHorizontal::FlipHorizontal() {}

void FlipHorizontal::Apply(ALLEGRO_BITMAP* img) {
	al_lock_bitmap(img, al_get_bitmap_format(img), ALLEGRO_LOCK_READWRITE);
	ALLEGRO_BITMAP* bmp = al_get_target_bitmap();

	al_set_target_bitmap(img);

	int w = al_get_bitmap_width(img);
	int h = al_get_bitmap_height(img);

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w / 2; j++)
		{
			ALLEGRO_COLOR c1 = al_get_pixel(img, j, i);
			ALLEGRO_COLOR c2 = al_get_pixel(img, w - 1 - j, i); //if a pixel is at j, its opposie is h-1-j
																//write at opposite locations
			al_put_pixel(j, i, c2);
			al_put_pixel(w - 1 - j, i, c1);
		}
	}
	al_unlock_bitmap(img);
	al_set_target_bitmap(bmp);
}

FlipHorizontal::~FlipHorizontal() {}

Channel::Channel() {
	int ch = rand() % 3;
}

void Channel::Apply(ALLEGRO_BITMAP* img) {
		//5 steps in processing a bitmap. only step 3 is different

		///////////////////////////////////////////////////////////////////////////////////////
		//1. current target of graphic operations. usually secondary buffer on graphic card
		ALLEGRO_BITMAP* target = al_get_target_bitmap();
		al_set_target_bitmap(img);

		///////////////////////////////////////////////////////////////////////////////////////
		//2. copy from graphic card to system RAM
		al_lock_bitmap(img, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READWRITE);

		///////////////////////////////////////////////////////////////////////////////////////
		//3. perform all the read/write operations on all pixels we need
		//
		//get bitmap dimensions
		int w = al_get_bitmap_width(img);
		int h = al_get_bitmap_height(img);
		//go through all pixels
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				//read colour value
				ALLEGRO_COLOR c = al_get_pixel(img, i, j);
				unsigned char r, g, b;
				//get rgb values
				al_unmap_rgb(c, &r, &g, &b);
				//set unwanted channels to 0
				if (ch== 0) //red
				{
					g = b = 0;
				}
				if (ch == 1) //green
				{
					r = b = 0;
				}
				if (ch == 2) //blue
				{
					g = r = 0;
				}
				//create the new value
				c = al_map_rgb(r, g, b);
				//write the new value
				al_put_pixel(i, j, c);
			}
		}

		///////////////////////////////////////////////////////////////////////////////////////
		//4. copy back to graphic card
		al_unlock_bitmap(img);

		///////////////////////////////////////////////////////////////////////////////////////
		//5. set target back to what it was
		al_set_target_bitmap(target);
}

Channel::~Channel() {}