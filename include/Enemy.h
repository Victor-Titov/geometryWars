#pragma once
#include "Engine.h"
#include "Entity.h"
class Enemy : public Entity
{
public:
	virtual void init(Drawable drawable, int velocity, double starting_angle);
	virtual void update(float2 playerPos);
	void reset();
	bool isAlive();
	int getType();
	virtual int getBulletAmount();
	virtual float2 getBulletCenter(int index);
	virtual void destroyBullet(int index);
	virtual int getBulletRadius();
protected:
	bool m_allive;
	int m_type;//1- shterev 2- bashi 3-frenski 4- kurshi

	
};
