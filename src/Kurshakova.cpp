#include "Kurshakova.h"
#include"Presenter.h"
Kurshakova::Kurshakova()
{
}

Kurshakova::~Kurshakova()
{
}

void Kurshakova::init(Drawable drawable, int velocity)
{
	m_drawable = drawable;
	m_velocity = velocity;
	coor = { (float)drawable.rect.x,(float)drawable.rect.y };
	m_bulletDrawable.rect = { 0,0,50,50 };
	m_bulletDrawable.texture = loadTexture("shield.bmp");
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
	BFFS = 1000;
	m_currFrames = 0;
	m_trueVelocity = m_velocity;
	m_allive = true;
	m_type = 4;
}

void Kurshakova::update(float2 playerPos)
{
	m_angle = atan2(playerPos.y - m_centerCoords.y, playerPos.x - m_centerCoords.x) * 180 / M_PI;

	m_shootingAngle = m_angle;
	m_velocity = m_trueVelocity * proximityCheck(playerPos);
	SDL_Rect ScreenRect = { 0,0,1920,1080 };
	
		shoot();
	
	for (int i = 0; i < m_waves.size(); i++) {
		m_waves[i].update();
		if (!collRectRect(ScreenRect, m_waves[i].getRect())) {
			destroyBullet(i);
		}
	}
	moveEntity();

}

void Kurshakova::draw()
{
	drawObjectEx(m_drawable, m_angle);
	for (int i = 0; i < m_waves.size(); i++) {
		m_waves[i].draw();
	}
}

void Kurshakova::destroy()
{
	SDL_DestroyTexture(m_drawable.texture);
	SDL_DestroyTexture(m_bulletDrawable.texture);
}

int Kurshakova::getBulletAmount()
{
	return m_waves.size();
}

int Kurshakova::getBulletRadius()
{
	return m_waves[0].getRadius();
}

float2 Kurshakova::getBulletCenter(int index)
{
	return m_waves[index].getCeneterCoords();
}

void Kurshakova::destroyBullet(int index)
{
	m_waves.erase(m_waves.begin() + index);
}



void Kurshakova::shoot()
{
	if (m_currFrames >= BFFS * DELTA_TIME) {
		Soundwave _Bullet;

		m_bulletDrawable.rect.x = m_drawable.rect.x + m_drawable.rect.w / 2;
		m_bulletDrawable.rect.y = m_drawable.rect.y + m_drawable.rect.h / 2;
		_Bullet.init(m_bulletDrawable, 2, m_shootingAngle);
		m_waves.push_back(_Bullet);

		
		m_currFrames = 0;
	}
	m_currFrames++;
}

int Kurshakova::proximityCheck(float2 playerPos)
{
	float dist;

	dist = playerDistance(playerPos);
	if (dist < 400) {
		return -1;
	}
	if (dist < 500) {
		return 0;
	}
	return 1;
}

