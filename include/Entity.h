#pragma once
#include "Engine.h"

class Entity {
public:
	virtual void init();
	virtual void update();
	virtual void draw();
	virtual void destroy();
	SDL_Rect getRect();
protected:
	int m_velocity;
	double m_angle;
	virtual void moveEntity();
	Drawable m_drawable;
	float2 coor;
};