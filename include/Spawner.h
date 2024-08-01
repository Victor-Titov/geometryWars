#pragma once
#include "Enemy.h"

class Spawner {
public:
	static vector<Enemy> m_enemies;
	void init();
	void update(float2 playerPos);
	void draw();
	void destroy();
private:
	Drawable m_enemy;
	int m_enemyAmount;
	int m_enemyVelocity;
	int m_enemyAngle;
	
	void spawnEnemies();
	void getEnemySpawn();
};