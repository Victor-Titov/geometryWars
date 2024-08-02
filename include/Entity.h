#pragma once
#include "Engine.h"

class Entity {
public:
	virtual void init();
	virtual void update();
	virtual void draw();
	virtual void destroy();
	virtual void setCoords(float2);
	virtual void setAngle(float);
	int get_health();
	int get_maxHealth();
	SDL_Rect getRect();
	int getRadius();
	float2 getCoords();
	float2 getCeneterCoords();
protected:
	int m_velocity;
	int m_radius;
	int m_health;
	int m_maxHealth;
	double m_angle;
	virtual void moveEntity();
	float findForce(int mass1, int mass2, float distance);
	Drawable m_drawable;
	float2 coor;
	SDL_Texture* m_faces[4];
	float2 m_centerCoords;
};