#pragma once
#include "Enemy.h"
#include "Basheva.h"
#include "Entity.h"
class Spawner {
public:
	static vector<Enemy*> m_enemies;
	
	Basheva m_bashi;
	void init();
	void update(float2 playerPos);
	void draw();
	void destroy();
private:
	Drawable m_enemy;
	Drawable m_basheva;
	int m_enemyAmount;
	int m_enemyVelocity;
	int m_enemyAngle;
	
	void spawnEnemies();
	void flockCollision();
	void getEnemySpawn();
};