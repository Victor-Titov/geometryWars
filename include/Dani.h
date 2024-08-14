#pragma once
#include"Enemy.h"
#include"Football.h"
class Dani : public Enemy {
public:
	void init(Drawable drawable, int velocity);
	void update(float2 playerPos);
	void draw();
	void destroy();
	int getBulletAmount();
	int getBulletRadius();
	float2 getBulletCenter(int index);

	void destroyBullet(int index);
	int m_maxFootballs;
private:
	void shoot();
	vector<Football> m_footballs;
	int proximityCheck(float2 playerPos);
	float playerDistance(float2 playerPos);
	int m_shootingAngle;
	int m_bulletRadius;
	int m_trueVelocity;
	int BFFS;
	Drawable m_bulletDrawable;
	int m_currFrames;
};

