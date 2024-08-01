#pragma once
#include "Engine.h"

class Entity {
public:
	virtual void init();
	virtual void update();
	virtual void draw();
	virtual void destroy();
	int get_health();
	int get_maxHealth();
	SDL_Rect getRect();
protected:
	int m_velocity;
	int m_health;
	int m_maxHealth;
	double m_angle;
	virtual void moveEntity();
	Drawable m_drawable;
	float2 coor;
	SDL_Texture* m_faces[4];
};