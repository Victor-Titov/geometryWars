#pragma once
#include "Engine.h"

class Entity {
public:
	virtual void init();
	virtual void update();
	virtual void draw();
	virtual void destroy();
	SDL_Rect getRect();
	int getRadius();
	float2 getCoords();
	float2 getCeneterCoords();
protected:
	int m_velocity;
	int m_radius;
	double m_angle;
	virtual void moveEntity();
	Drawable m_drawable;
	float2 coor;
	float2 m_centerCoords;
};