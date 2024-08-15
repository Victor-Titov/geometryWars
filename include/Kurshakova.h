#pragma once 
#include "Basheva.h"
#include"Soundwave.h"
class Kurshakova : public Basheva {
public:
	Kurshakova();
	~Kurshakova();
	void init(Drawable drawable, int velocity);
	void update(float2 playerPos);
	void draw();
	void destroy();
	int getBulletAmount();
	int getBulletRadius();
	float2 getBulletCenter(int index);

	void destroyBullet(int index);

protected:
	void shoot();
	int proximityCheck(float2 playerPos);
	vector<Soundwave>m_waves;
	
};