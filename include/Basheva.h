#pragma once

#include "Entity.h"
#include "Bullet.h"
class Basheva : public Entity {
public:
	Basheva();
	~Basheva();
	void init(Drawable drawable, int velocity);
	void update(float2 playerPos);
	void draw();
	void destroy();
	int getBulletAmount();
	int getBulletRadius();
	float2 getBulletCenter(int index);

	void destroyBullet(int index);
	float2 getCoords();
	float2 getCenterCoords();
private:
	int proximityCheck(float2 playerPos);
	void shoot();
	float playerDistance(float2 playerPos);
	int m_shootingAngle;
	vector<Bullet> m_bullets;
	int m_bulletRadius;
	int m_trueVelocity;
	int BFFS;
	Drawable m_bulletDrawable;
	int m_currFrames;
};