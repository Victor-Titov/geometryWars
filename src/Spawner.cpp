#include "Spawner.h"
#include "Presenter.h"
vector<Enemy> Spawner::m_enemies = vector<Enemy>();
vector<Basheva> Spawner::m_bashevas = vector<Basheva>();
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
	
	m_basheva.rect = { 100,100,300,300 };
	m_basheva.texture = loadTexture("right_view.bmp");
	spawnEnemies();
	
}

void Spawner::update(float2 playerPos)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i].update(playerPos);
		if (!m_enemies[i].isAlive()) {
			m_enemies.erase(m_enemies.begin() + i);
			

		}

		
	}
	for (int i = 0; i < m_bashevas.size(); i++) {
		m_bashevas[i].update(playerPos);
	}
	spawnEnemies();
		//SDL_Delay(9999999);
	
}

void Spawner::draw()
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i].draw();
	}
	for (int i = 0; i < m_bashevas.size(); i++) {
		m_bashevas[i].draw();
	}
	
	
}

void Spawner::destroy()
{
	SDL_DestroyTexture(m_enemy.texture);
	SDL_DestroyTexture(m_basheva.texture);
}



void Spawner::spawnEnemies()
{
	while (m_enemies.size() + m_bashevas.size() < m_enemyAmount) {

		int type = rand()%2+1;
		type = 2;
		getEnemySpawn();
		Enemy _Enemy;
		switch (type) {
		case 1:
			
			_Enemy.init(m_enemy, m_enemyVelocity, 0);
			m_enemies.push_back(_Enemy);
			break;
		case 2:
			Basheva _Basheva;
			_Basheva.init(m_basheva,1);
			m_bashevas.push_back(_Basheva);
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
	m_basheva.rect.x = m_enemy.rect.x;
	m_basheva.rect.y = m_enemy.rect.y;
	
}


