#include "Basheva.h"
#include"Presenter.h"
Basheva::Basheva()
{
}

Basheva::~Basheva()
{
}

void Basheva::init(Drawable drawable, int velocity)
{
	m_drawable = drawable;
	m_velocity = velocity;
	coor = { (float)drawable.rect.x,(float)drawable.rect.y };
	m_bulletDrawable.rect = { 0,0,50,50 };
	m_bulletDrawable.texture = loadTexture("bullet.bmp");
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
	BFFS = 15;
	m_currFrames = 0;
	m_trueVelocity = m_velocity;
}



void Basheva::update(float2 playerPos)
{
	m_angle = atan2(playerPos.y - m_centerCoords.y, playerPos.x - m_centerCoords.x) * 180 / M_PI;
	//TO FIX
	// basheva draw,shooting angly with revesed y
	m_shootingAngle = m_angle;
	m_velocity = m_trueVelocity * proximityCheck(playerPos);
	SDL_Rect ScreenRect = { 0,0,1920,1080 };
	if (playerDistance(playerPos) < 350) {
		shoot();
	}
	for (int i = 0; i < m_bullets.size(); i++) {
		m_bullets[i].update();
		if (!collRectRect(ScreenRect, m_bullets[i].getRect())) {
			destroyBullet(i);
		}
	}
	moveEntity();
}

void Basheva::draw()
{
	drawObjectEx(m_drawable, m_angle);
	for (int i = 0; i < m_bullets.size(); i++) {
		m_bullets[i].draw();
	}
}

void Basheva::destroy()
{
	SDL_DestroyTexture(m_drawable.texture);
	SDL_DestroyTexture(m_bulletDrawable.texture);
}

int Basheva::getBulletAmount()
{
	return m_bullets.size();
}

int Basheva::getBulletRadius()
{
	return m_bulletRadius;
}

float2 Basheva::getBulletCenter(int index)
{
	return m_bullets[index].getCeneterCoords();
}

void Basheva::destroyBullet(int index)
{
	m_bullets.erase(m_bullets.begin() + index);
}

float2 Basheva::getCoords()
{
	return coor;
}

float2 Basheva::getCenterCoords()
{
	return m_centerCoords;
}

int Basheva::proximityCheck(float2 playerPos)
{
	float dist;
	
	dist = playerDistance(playerPos);
	if (dist < 200) {
		return -1;
	}
	if (dist < 300) {
		return 0;
	}
	return 1;
}

void Basheva::shoot()
{
	if (m_currFrames >= BFFS) {
		Bullet _Bullet;
		
		m_bulletDrawable.rect.x = m_drawable.rect.x + m_drawable.rect.w / 2;
		m_bulletDrawable.rect.y = m_drawable.rect.y + m_drawable.rect.h / 2;
		_Bullet.init(m_bulletDrawable, 20, m_shootingAngle);
		m_bullets.push_back(_Bullet);

		m_currFrames = 0;
	}
	m_currFrames++;
}

float Basheva::playerDistance(float2 playerPos)
{
	float distX, distY, dist;
	distX = abs(m_centerCoords.x - playerPos.x);
	distY = abs(m_centerCoords.y - playerPos.y);
	dist = sqrt(distX * distX + distY * distY);
	return dist;
}
