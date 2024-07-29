#include "Player.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include <cmath>


Player::Player()
{
}

Player::~Player()
{
}

void Player::init()
{
	m_player.texture = loadTexture("rock.bmp");
	m_player.rect = { 800, 500, 100, 100};
	coor = { 800, 500};
}

void Player::update()
{
	movePlayer(30, 2);
}

void Player::draw()
{
	drawObjectEx(m_player, 40);
}

void Player::destroy()
{
	SDL_DestroyTexture(m_player.texture);
}

void Player::movePlayer(float degrees, float velocity)
{
	float rad = degrees * (M_PI / 180);
	float y_offset = sin(rad) * (-1);
	float x_offset = cos(rad);

	cout << y_offset << "" << x_offset << endl;

	coor.y += y_offset * velocity;
	coor.x += x_offset * velocity;

	m_player.rect.y = coor.y;
	m_player.rect.x = coor.x;
	
}
