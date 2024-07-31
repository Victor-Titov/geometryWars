#include "Board.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Player.h"

Board::Board()
{

}

Board::~Board()
{

}

void Board::init()
{
	string configFile = "boardInit.txt";

	fstream stream;

	string backgorundImg, tmp;

	stream.open(CONFIG_FOLDER + configFile);

    stream >> tmp >> backgorundImg;

	stream.close();

	m_background = loadTexture(backgorundImg);

	m_player.init();
	m_spawner.init();
	
}

void Board::update()
{
	m_player.update();
	m_spawner.update();

}

void Board::draw()
{
	drawObject(m_background);
	m_player.draw();
	m_spawner.draw();
}

void Board::destroy()
{
	SDL_DestroyTexture(m_background);
	m_player.destroy();
	m_spawner.destroy();
}