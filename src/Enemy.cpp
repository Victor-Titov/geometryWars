#include "Enemy.h"

void Enemy::init(Drawable drawable, int velocity, double starting_angle)
{
	m_drawable.rect = drawable.rect;
	m_drawable.texture = drawable.texture;
	m_velocity = velocity;
	m_angle = starting_angle;
	coor = { (float)drawable.rect.x,(float) drawable.rect.y };
	m_allive = true;
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
}

void Enemy::update(float2 playerPos)
{
	m_angle = atan2(playerPos.y - coor.y, playerPos.x - coor.x) * 180 / M_PI;
	moveEntity();
}

void Enemy::reset()
{
	m_allive = false;
}

bool Enemy::isAlive()
{
	return m_allive;
}

float2 Enemy::getCoords()
{
	return coor;
}

float2 Enemy::getCenterCoords()
{
	return m_centerCoords;
}



void Enemy::home()
{
}
