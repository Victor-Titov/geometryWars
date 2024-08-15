#include "Soundwave.h"

Soundwave::Soundwave()
{
}

Soundwave::~Soundwave()
{
}

void Soundwave::init(Drawable drawable, int velocity, int angle)
{
	m_drawable = drawable;
	m_velocity = velocity;
	m_angle = angle;
	coor.x = drawable.rect.x;
	coor.y = drawable.rect.y;
	m_radius = max(m_drawable.rect.w, m_drawable.rect.h);
	m_trueHeight = m_drawable.rect.h;
	m_dissopationRate = 40;
	//cout << "BALLS";
}

void Soundwave::moveEntity()
{
	float rad = m_angle * (M_PI / 180);
	float y_offset = sin(rad);
	float x_offset = cos(rad);

	//cout << y_offset << "" << x_offset << endl;

	coor.y += y_offset * m_velocity / DELTA_TIME;
	coor.x += x_offset * m_velocity / DELTA_TIME;

	m_drawable.rect.y = coor.y;
	m_drawable.rect.x = coor.x;
	
	if (counter >= m_dissopationRate) {
		coor.y -= 1;
		m_trueHeight += 1;
		counter = 0;
	}
	m_drawable.rect.h = m_trueHeight;
	m_centerCoords.x = coor.x + m_drawable.rect.w / 2;
	m_centerCoords.y = coor.y + m_drawable.rect.h / 2;
	counter++;
	//cout << "BALLS\n";
}
