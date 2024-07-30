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
	m_drawable.texture = loadTexture("rock.bmp");
	m_drawable.rect = { 800, 500, 100, 100};
	coor = { 800, 500};
	m_velocity = 2;
	m_angle = 30;
}

void Player::update()
{
	moveEntity();
}


