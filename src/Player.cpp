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
	m_drawable.texture = loadTexture("rocket_with_cat.bmp");
	m_drawable.rect = { 800, 500, 100, 100};
	coor = { 800, 500};
	m_velocity = 2;
	m_angle = 0;
	m_bulletDrawable.texture = loadTexture("bullet.bmp");
	m_bulletDrawable.rect.w = 50;
	m_bulletDrawable.rect.h = 50;
	m_currentBullet = 0;
	m_currFrames = 0;
}

void Player::update()
{
	movePlayer();
	SDL_Rect screenRect = { 0, 0, Presenter::m_SCREEN_WIDTH, Presenter::m_SCREEN_HEIGHT };
	for (int i = 0; i <m_bullets.size(); i++) {
		m_bullets[i].update();
		if (!collRectRect(screenRect, m_bullets[i].getRect())) {
			m_bullets.erase(m_bullets.begin() + i);
		}
	}

	shoot();

}

void Player::draw()
{
	if (InputManager::m_joystickPosition.x != 0 || InputManager::m_joystickPosition.y!=0) {
		m_angle = atan2(InputManager::m_joystickPosition.y, InputManager::m_joystickPosition.x) * 180 / M_PI;
		//cout << angle << endl;
	}
	//cout << angle << endl;
	for (int i = 0; i < m_bullets.size(); i++) {
		m_bullets[i].draw();
	}
	drawObjectEx(m_drawable, m_angle);
}

float2 Player::getCoords()
{
	return coor;
}




void Player::movePlayer()
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
		Bullet _Bullet;
		m_bulletDrawable.rect.x = m_drawable.rect.x + m_drawable.rect.w / 2;
		m_bulletDrawable.rect.y = m_drawable.rect.y + m_drawable.rect.h / 2;
		_Bullet.init(m_bulletDrawable, 20, m_angle);
		m_bullets.push_back(_Bullet);
		
		m_currFrames = 0;
	}
	m_currFrames++;
}
