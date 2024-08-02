#pragma once
#include "Engine.h"
#include "Entity.h"
class Enemy : public Entity
{
public:
	void init(Drawable drawable, int velocity, double starting_angle);
	void update(float2 playerPos);
	void reset();
	bool isAlive();
	float2 getCoords();
	float2 getCenterCoords();
private:
	bool m_allive;
	
	void home();
	
};
