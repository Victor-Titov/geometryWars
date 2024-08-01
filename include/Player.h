#pragma once

#include "Engine.h"
#include <cmath>
#include "Bullet.h"
#include "Entity.h"
#include "BarManager.h"

#define FFS 5 // frames needed to shoot once
class Player : public Entity
{
public:
	Player();
	~Player();

	void init();
	void update();
	void draw();
	float2 getCoords();
private:
	void movePlayer();
	void shoot();
	vector<Bullet> m_bullets;
	Drawable m_bulletDrawable;
	int m_currentBullet;
	int m_currFrames;
	double m_pBulletsAngle;
	void checkCollisions();
	Bar m_healthBar;
};