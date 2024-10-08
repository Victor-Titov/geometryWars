#pragma once
#include"Basheva.h"
#include"Football.h"
class Dani : public Basheva {
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
	
};

