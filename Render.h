#pragma once
class Render
{
public:
	FlipVertical* flipV;
	FlipHorizontal* flipH;
	Channel* chan;
	Render();
	~Render();

	void Draw(GameObject* obj);
	void Draw(GameObject* obj, int effect);			//draw an object 
	void Begin(ALLEGRO_BITMAP* bg);		//start a frame by drawing the background and other possible actions
	void End();							//end the frame by moving to primary buffer and other possible actions
};

