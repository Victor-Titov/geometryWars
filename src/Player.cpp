#include "Player.h"
#include "Presenter.h"
#include "InputManager.h"
#include "SoundManager.h"
#include <cmath>

#include "Spawner.h"
Player::Player()
{
}

Player::~Player()
{
}

void Player::init()
{
	m_faces[0] = loadTexture("front_view.bmp");
	m_faces[1] = loadTexture("back_view.bmp");
	m_faces[2] = loadTexture("left_view.bmp");
	m_faces[3] = loadTexture("right_view.bmp");
	m_drawable.texture = loadTexture("front_view.bmp");
	m_drawable.rect = { 800, 500, 300, 300};
	coor = { 800, 500};
	m_velocity = 2;
	m_angle = 0;
	m_bulletDrawable.texture = loadTexture("bullet.bmp");
	m_bulletDrawable.rect.w = 50;
	m_bulletDrawable.rect.h = 50;
	m_currentBullet = 0;
	m_currFrames = 0;
	m_maxHealth = 100;
	m_health = m_maxHealth;
	m_healthBar.init("health_bar.txt");
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
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

	if (InputManager::m_secondstickPosition.y != 0 || InputManager::m_secondstickPosition.x != 0) {
		shoot();
	}
	checkCollisions();
	
	m_healthBar.setBar(m_health, m_maxHealth);
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
	m_drawable.texture = m_faces[InputManager::m_faceNum];
	drawObjectEx(m_drawable, m_angle);
	m_healthBar.draw();
}

void Player::destroy()
{
	for (int i = 0; i < 4; i++) {
		SDL_DestroyTexture(m_faces[i]);
	}
	SDL_DestroyTexture(m_drawable.texture);
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
	m_centerCoords.x = coor.x + m_drawable.rect.w / 2;
	m_centerCoords.y = coor.y + m_drawable.rect.h / 2;
	
	
}

void Player::shoot()
{
	if (m_currFrames >= FFS) {
		Bullet _Bullet;
		m_pBulletsAngle = atan2(InputManager::m_secondstickPosition.y, InputManager::m_secondstickPosition.x) * 180/M_PI;
		m_bulletDrawable.rect.x = m_drawable.rect.x + m_drawable.rect.w / 2;
		m_bulletDrawable.rect.y = m_drawable.rect.y + m_drawable.rect.h / 2;
		_Bullet.init(m_bulletDrawable, 20, m_pBulletsAngle);
		m_bullets.push_back(_Bullet);
		
		m_currFrames = 0;
	}
	m_currFrames++;
}

void Player::checkCollisions()
{
	//cout << "oh no\n";
	for (int i = 0; i < Spawner::m_enemies.size(); i++) {
		//cout << m_centerCoords.x << ' ' << m_centerCoords.y << ' ' << m_radius << ' ' << Spawner::m_enemies[i].getCeneterCoords().x << ' ' << Spawner::m_enemies[i].getCeneterCoords().y << ' ' << Spawner::m_enemies[i].getRadius() << '\n';
		if (CollCircleCircle(m_centerCoords,m_radius,Spawner::m_enemies[i].getCeneterCoords(), Spawner::m_enemies[i].getRadius())) {
			Spawner::m_enemies[i].reset();
			
		}
		for (int j = 0; j < m_bullets.size(); j++) {
			if (CollCircleCircle(m_bullets[j].getCeneterCoords(), m_bullets[j].getRadius(), Spawner::m_enemies[i].getCeneterCoords(), Spawner::m_enemies[i].getRadius())) {
				Spawner::m_enemies[i].reset();
				m_bullets.erase(m_bullets.begin()+j);
			}
		}
	}

	for (int i = 0; i < Spawner::m_bashevas.size(); i++) {
		for (int j = 0; j < Spawner::m_bashevas[i].getBulletAmount(); j++) {
			if (CollCircleCircle(Spawner::m_bashevas[i].getBulletCenter(j), Spawner::m_bashevas[i].getBulletRadius(), m_centerCoords, m_radius)) {
				Spawner::m_bashevas[i].destroyBullet(j);
			}
		}
	}
}
