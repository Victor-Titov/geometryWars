#include "Bullet.h"

void Bullet::init(Drawable drawable, int velocity, int angle)
{
	m_drawable = drawable;
	m_velocity = velocity;
	m_angle = angle;
	coor.x = drawable.rect.x;
	coor.y = drawable.rect.y;
}

void Bullet::update()
{
	moveEntity();
}

