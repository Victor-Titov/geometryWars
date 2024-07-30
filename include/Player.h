#pragma once

#include "Engine.h"
#include <cmath>

class Player
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();
	void destroy();
	void movePlayer();

private:
	Drawable m_player;
	float2 coor = {0, 0};
};