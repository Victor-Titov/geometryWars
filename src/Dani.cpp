#include "Dani.h"
#include"Presenter.h"
void Dani::init(Drawable drawable, int velocity)
{
	m_drawable = drawable;
	m_velocity = velocity;
	coor = { (float)drawable.rect.x,(float)drawable.rect.y };
	m_bulletDrawable.rect = { 0,0,100,100 };
	m_bulletDrawable.texture = loadTexture("Shield.bmp");
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
	BFFS = 1000;
	m_currFrames = 0;
	m_trueVelocity = m_velocity;
	m_allive = true;
	m_type = 3;
	m_maxFootballs = 3;
}

void Dani::update(float2 playerPos)
{
	m_angle = atan2(playerPos.y - m_centerCoords.y, playerPos.x - m_centerCoords.x) * 180 / M_PI;

	m_shootingAngle = m_angle;
	m_velocity = m_trueVelocity * proximityCheck(playerPos);
	SDL_Rect ScreenRect = { 0,0,1920,1080 };
	
		shoot();
	
	for (int i = 0; i < m_footballs.size(); i++) {
		m_footballs[i].update();
		
	}
	moveEntity();
}

void Dani::draw()
{
	drawObjectEx(m_drawable,m_angle);
	for (int i = 0; i < m_footballs.size(); i++) {
		m_footballs[i].draw();

	}
}

void Dani::destroy()
{
	SDL_DestroyTexture(m_drawable.texture);
	SDL_DestroyTexture(m_bulletDrawable.texture);
}

int Dani::getBulletAmount()
{
    return m_footballs.size();
}

int Dani::getBulletRadius()
{
    return 100;
}

float2 Dani::getBulletCenter(int index)
{
    return m_footballs[index].getCeneterCoords();
}

void Dani::destroyBullet(int index)
{
	m_footballs.erase(m_footballs.begin() + index);
}

void Dani::shoot()
{
	if (m_currFrames >= BFFS * DELTA_TIME  && m_footballs.size()<m_maxFootballs) {
		Football _Football;

		m_bulletDrawable.rect.x = m_drawable.rect.x + m_drawable.rect.w / 2;
		m_bulletDrawable.rect.y = m_drawable.rect.y + m_drawable.rect.h / 2;
		_Football.init(m_bulletDrawable, 3, m_shootingAngle);
		m_footballs.push_back(_Football);

		m_currFrames = 0;
	}
	m_currFrames++;
}

int Dani::proximityCheck(float2 playerPos)
{
	float dist;

	dist = playerDistance(playerPos);
	if (dist < 300) {
		return -1;
	}
	if (dist < 400) {
		return 0;
	}
	return 1;
}

float Dani::playerDistance(float2 playerPos)
{
	float distX, distY, dist;
	distX = abs(m_centerCoords.x - playerPos.x);
	distY = abs(m_centerCoords.y - playerPos.y);
	dist = sqrt(distX * distX + distY * distY);
	return dist;
}
