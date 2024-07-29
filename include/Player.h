#pragma once

#include "Engine.h"

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();
	void destroy();
	void movePlayer(float degrees, float velocity);

private:
	Drawable m_player;
	float2 coor = {0, 0};
};