#pragma once

#include "Engine.h"
#include <cmath>
#include "Bullet.h"
#include "Entity.h"
#define NUMBER_OF_BULLETS 200
#define FFS 8 // frames needed to shoot once
class Player : public Entity
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();

private:
	float2 movePlayer();
	void shoot();
	Bullet m_bullets[NUMBER_OF_BULLETS];
	Drawable m_bulletDrawable;
	int m_currentBullet;
	int m_currFrames;
	double m_pBulletsAngle;
};