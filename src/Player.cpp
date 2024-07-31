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
	m_bulletDrawable.texture = loadTexture("bullet.bmp");
	m_bulletDrawable.rect.w = 50;
	m_bulletDrawable.rect.h = 50;
	m_currentBullet = 0;
	m_currFrames = 0;
}

void Player::update()
{
	moveEntity();
	for (int i = 0; i < NUMBER_OF_BULLETS; i++) {
		m_bullets[i].update();
	}

	shoot();

}

void Player::draw()
{
	drawObjectEx(m_drawable, m_angle);
	for (int i = 0; i < NUMBER_OF_BULLETS; i++) {
		m_bullets[i].draw();
	}
}





void Player::moveEntity()
{
	int velocity = 10;

	//float rad = degrees * (M_PI / 180);
	//float y_offset = sin(rad) * (-1);
	//float x_offset = cos(rad);


	coor.y += (InputManager::m_joystickPosition.y / 32767.0) * velocity;
	coor.x += (InputManager::m_joystickPosition.x / 32767.0) * velocity;

	m_drawable.rect.y = coor.y;
	m_drawable.rect.x = coor.x;
	
	
}

void Player::shoot()
{
	if (m_currFrames >= FFS) {
		m_bulletDrawable.rect.x = m_drawable.rect.x + m_drawable.rect.w / 2;
		m_bulletDrawable.rect.y = m_drawable.rect.y + m_drawable.rect.h / 2;
		m_bullets[m_currentBullet].init(m_bulletDrawable, 5, m_angle);
		m_currentBullet++;
		if (m_currentBullet >= NUMBER_OF_BULLETS) {
			m_currentBullet = 0;
		}
		m_currFrames = 0;
	}
	m_currFrames++;
}
