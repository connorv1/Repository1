#pragma once

class Effect
{
public:
	Effect();
	~Effect();

	void Apply(ALLEGRO_BITMAP* img);
};

class FlipVertical : public Effect
{
public:
	FlipVertical();
	~FlipVertical();
	void Apply(ALLEGRO_BITMAP* img);
};

class FlipHorizontal : public Effect
{
public:
	FlipHorizontal();
	~FlipHorizontal();
	void Apply(ALLEGRO_BITMAP* img);
};

class Channel : public Effect
{
public:
	Channel();
	~Channel();
	void Apply(ALLEGRO_BITMAP* img);
	int ch;

};