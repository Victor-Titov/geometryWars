#include "Football.h"
#include "Presenter.h"
Football::Football()
{
}
Football::~Football()
{
}
void Football::moveEntity()
{
	float rad = m_angle * (M_PI / 180);
	float y_offset = sin(rad);
	float x_offset = cos(rad);

	//cout << y_offset << "" << x_offset << endl;

	coor.y += y_offset * m_velocity / DELTA_TIME * m_yOffset;
	coor.x += x_offset * m_velocity / DELTA_TIME * m_xOffset;

	if (coor.x + m_drawable.rect.w > Presenter::m_SCREEN_WIDTH || coor.x < 0) {
		m_xOffset *= -1;
		

	}

	if (coor.y + m_drawable.rect.h > Presenter::m_SCREEN_HEIGHT || coor.y < 0) {
		m_yOffset *= -1;
		
	}
	
	
	m_drawable.rect.y = coor.y;
	m_drawable.rect.x = coor.x;

	m_centerCoords.x = coor.x + m_drawable.rect.w / 2;
	m_centerCoords.y = coor.y + m_drawable.rect.h / 2;

	


	
}
