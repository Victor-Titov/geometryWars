#pragma once

#include "Engine.h"
#include "Player.h"
#include "InputManager.h"

class Board
{
public:
	Board();
	~Board();

	void init();
	void update();
	void draw();
	void destroy();

private:
	SDL_Texture* m_background;
	Player m_player;
};