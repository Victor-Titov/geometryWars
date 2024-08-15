#pragma once

#include "Engine.h"
#include "Player.h"
#include "Spawner.h"
#include "InputManager.h"
#include"Kurshakova.h"
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
	Spawner m_spawner;
	float2 m_playerCoords;
	

};