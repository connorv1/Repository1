#include "Main.h"

//external variable is defined in another source file
extern ALLEGRO_FONT *g_font;

Render::Render()
{
}


Render::~Render()
{
}

void Render::Draw(GameObject* obj) {
	ALLEGRO_BITMAP* bmp = al_clone_bitmap(obj->GetShape());
}

void Render::Draw(GameObject* obj, int effect)
{
	ALLEGRO_BITMAP* bmp = al_clone_bitmap(obj->GetShape());

	int w = al_get_bitmap_width(obj->GetShape());
	int h = al_get_bitmap_height(obj->GetShape());
	if (effect == 0) {
		flipV->Apply(bmp);
	}
	else if (effect == 1) {
		flipH->Apply(bmp);
	}
	else if (effect == 2) {
		chan->Apply(bmp);
	}
	al_draw_bitmap(bmp, obj->position.x, obj->position.y, 0);
	al_destroy_bitmap(bmp);
}

void Render::Begin(ALLEGRO_BITMAP* bg)
{
	al_draw_bitmap(bg, 0, 0, 0);
}
void Render::End()
{
	char text[] = "Sample Game";
	al_draw_text(g_font, al_map_rgb(255, 255, 255), 0, 0, 0, text);

	al_flip_display();
}