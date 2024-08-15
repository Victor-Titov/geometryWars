#pragma once
#include "Enemy.h"
#include "Basheva.h"
#include "Entity.h"
#include "Dani.h"
#include "Kurshakova.h"
#define SPAWN_COOLDOWN 100
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
	Drawable m_dani;
	Drawable m_Kurshakova;
	int m_enemyAmount;
	int m_enemyVelocity;
	int m_enemyAngle;
	int m_cooldown;
	void spawnEnemies();
	void flockCollision();
	void getEnemySpawn();
};