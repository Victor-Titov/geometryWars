#pragma once
#include "Enemy.h"

class Spawner {
public:
	void init();
	void update();
	void draw();
	void destroy();
private:
	Drawable m_enemy;
	int m_enemyAmount;
	int m_enemyVelocity;
	int m_enemyAngle;
	vector<Enemy> m_enemies;
};