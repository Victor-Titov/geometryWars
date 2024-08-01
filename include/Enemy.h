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
	
private:
	bool m_allive;
	
	void home();
	
};
