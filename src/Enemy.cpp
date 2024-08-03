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
	m_type = 1;
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

int Enemy::getType()
{
	return m_type;
}

int Enemy::getBulletAmount()
{
	return 0;
}

float2 Enemy::getBulletCenter(int index)
{
	float2 a = { 0,0 };
	return a;
}

void Enemy::destroyBullet(int index)
{

}

int Enemy::getBulletRadius()
{
	return 0;
}

