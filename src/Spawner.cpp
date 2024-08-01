#include "Spawner.h"
#include "Presenter.h"
vector<Enemy> Spawner::m_enemies = vector<Enemy>();
void Spawner::init()
{
	fstream stream;
	string tmp, enemyTexture;
	stream.open(CONFIG_FOLDER + "spawner.txt");
	stream >> tmp >> enemyTexture;
	stream >> tmp >> m_enemy.rect.w >> m_enemy.rect.h;
	stream >> tmp >> m_enemyVelocity;
	stream >> tmp >> m_enemyAmount;
	stream.close();
	
	m_enemy.texture = loadTexture(enemyTexture);
	for (int i = 0; i < m_enemyAmount; i++) {
		getEnemySpawn();
		Enemy _Enemy;

		_Enemy.init(m_enemy, m_enemyVelocity, 0);
		//cout << "\n _Enemy.w: " << m_enemy.rect.x;
		m_enemies.push_back(_Enemy);
		
	}
}

void Spawner::update(float2 playerPos)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i].update(playerPos);
		if (!m_enemies[i].isAlive()) {
			m_enemies.erase(m_enemies.begin() + i);
			

		}

		
	}
	spawnEnemies();
		//SDL_Delay(9999999);
}

void Spawner::draw()
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i].draw();
	}
	
}

void Spawner::destroy()
{
	SDL_DestroyTexture(m_enemy.texture);
}



void Spawner::spawnEnemies()
{
	while (m_enemies.size() < m_enemyAmount) {
		int type = 1;
		getEnemySpawn();
		switch (type) {
		case 1:
			Enemy _Enemy;
			
			_Enemy.init(m_enemy, m_enemyVelocity, 0);
			m_enemies.push_back(_Enemy);
		}
	}
}

void Spawner::getEnemySpawn()
{
	int type = rand() % 4 + 1;
	switch (type)
	{
	case 1:
		m_enemy.rect.x = rand() % Presenter::m_SCREEN_WIDTH;
		m_enemy.rect.y = -100;
		break;
	case 2:
		m_enemy.rect.x= rand() % Presenter::m_SCREEN_WIDTH;
		m_enemy.rect.y = Presenter::m_SCREEN_HEIGHT + 100;
		break;
	case 3:
		m_enemy.rect.x = -100;
		m_enemy.rect.y = rand() % Presenter::m_SCREEN_HEIGHT;
		break;
	case 4:
		m_enemy.rect.x = Presenter::m_SCREEN_WIDTH + 100;
		m_enemy.rect.y = rand() % Presenter::m_SCREEN_HEIGHT;
		break;
	default:

		break;
	}
	
}


