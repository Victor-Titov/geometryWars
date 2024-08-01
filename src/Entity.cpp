#include "Entity.h"
#include "Presenter.h"
void Entity::init()
{
}

void Entity::update()
{
}


void Entity::draw()
{
	drawObjectEx(m_drawable, m_angle);
	
}


void Entity::destroy()
{
	SDL_DestroyTexture(m_drawable.texture);
}

SDL_Rect Entity::getRect()
{
	return m_drawable.rect;
}

int Entity::getRadius()
{
	return m_radius;
}

float2 Entity::getCoords()
{
	return coor;
}

float2 Entity::getCeneterCoords()
{
	return m_centerCoords;
}

void Entity::moveEntity()
{
	float rad = m_angle * (M_PI / 180);
	float y_offset = sin(rad) * (-1);
	float x_offset = cos(rad);

	//cout << y_offset << "" << x_offset << endl;

	coor.y += y_offset * m_velocity;
	coor.x += x_offset * m_velocity;

	m_drawable.rect.y = coor.y;
	m_drawable.rect.x = coor.x;
	m_centerCoords.x = coor.x + m_drawable.rect.w / 2;
	m_centerCoords.y = coor.y + m_drawable.rect.h / 2;
}
