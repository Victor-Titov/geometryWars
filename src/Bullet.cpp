#include "Bullet.h"

void Bullet::init(Drawable drawable, int velocity, int angle)
{
	m_drawable = drawable;
	m_velocity = velocity;
	m_angle = angle;
	coor.x = drawable.rect.x;
	coor.y = drawable.rect.y;
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
}

void Bullet::update()
{
	moveEntity();
}

void Bullet::moveEntity()
{
	float rad = m_angle * (M_PI / 180);
	float y_offset = sin(rad);
	float x_offset = cos(rad);

	//cout << y_offset << "" << x_offset << endl;

	coor.y += y_offset * m_velocity / DELTA_TIME;
	coor.x += x_offset * m_velocity / DELTA_TIME;

	m_drawable.rect.y = coor.y;
	m_drawable.rect.x = coor.x;
	m_centerCoords.x = coor.x + m_drawable.rect.w / 2;
	m_centerCoords.y = coor.y + m_drawable.rect.h / 2;
}

