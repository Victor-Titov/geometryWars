#pragma once

#include "Entity.h"
#include "Bullet.h"
#include "Enemy.h"
class Basheva : public  Enemy{
public:
	Basheva();
	~Basheva();
	virtual void init(Drawable drawable, int velocity);
	virtual void update(float2 playerPos);
	virtual void draw();
	virtual void destroy();
	virtual int getBulletAmount();
	virtual int getBulletRadius();
	virtual float2 getBulletCenter(int index);

	virtual void destroyBullet(int index);

protected:
	virtual void shoot();
	virtual int proximityCheck(float2 playerPos);
	float playerDistance(float2 playerPos);
	int m_shootingAngle;
	int m_bulletRadius;
	int m_trueVelocity;
	int BFFS;
	Drawable m_bulletDrawable;
	int m_currFrames;
private:
	vector<Bullet> m_bullets;
};