#include "Spawner.h"
#include "Presenter.h"
#include "Entity.h"
vector<Enemy*> Spawner::m_enemies = vector<Enemy*>();

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
	m_cooldown = 0;
	m_enemy.texture = loadTexture(enemyTexture);
	
	m_basheva.rect = { 100,100,300,300 };
	m_dani.rect = { 100,100,300,300 };
	m_dani.texture = loadTexture("Yes.bmp");
	m_basheva.texture = loadTexture("right_view.bmp");
	spawnEnemies();
	
}

void Spawner::update(float2 playerPos)
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i]->update(playerPos);
		if (!m_enemies[i]->isAlive()) {
			m_enemies.erase(m_enemies.begin() + i);
		}
	}

	spawnEnemies();
	flockCollision();
		//SDL_Delay(9999999);
	
}

void Spawner::draw()
{
	for (int i = 0; i < m_enemies.size(); i++) {
		m_enemies[i]->draw();
	}

	
	
}

void Spawner::destroy()
{
	SDL_DestroyTexture(m_enemy.texture);
	SDL_DestroyTexture(m_basheva.texture);
}



void Spawner::spawnEnemies()
{
	if (m_enemies.size()< m_enemyAmount) {
		if (m_cooldown>=SPAWN_COOLDOWN*DELTA_TIME) {
			int type = rand() % 3 + 1;
			//type = 2;
			getEnemySpawn();
			Enemy* _Enemy = new Enemy();
			Basheva * _Basheva = new Basheva();
			Dani * _Dani = new Dani();
			switch (type) {
			case 1:

				_Enemy->init(m_enemy, m_enemyVelocity, 0);
				m_enemies.push_back(_Enemy);
				break;
			case 2:
				_Basheva->init(m_basheva, 1);
				m_enemies.push_back(_Basheva);
				break;
			case 3:
				_Dani->init(m_dani, 1);
				m_enemies.push_back(_Dani);
				break;
			}
			m_cooldown = 0;
		}
		m_cooldown++;
		
		

	}
}

void Spawner::flockCollision()
{
	float2 object1Coor, object2Coor, tmp;
	float force, distance;
	int multiplier = 1000;
	

	for (int i = 0; i < Spawner::m_enemies.size(); i++) {
		for (int j = i + 1; j < Spawner::m_enemies.size() - 1; j++) {
			object1Coor = Spawner::m_enemies[i]->getCoords();
			object2Coor = Spawner::m_enemies[j]->getCoords();
			tmp.x = object2Coor.x - object1Coor.x;
			tmp.y = object2Coor.y - object1Coor.y;
			distance = sqrt(abs(object2Coor.y - object1Coor.y) * abs(object2Coor.y - object1Coor.y) + abs(object2Coor.x - object1Coor.x) * abs(object2Coor.x - object1Coor.x));
			force = Entity::findForce(1, 1, distance);
			force *= multiplier;
			tmp = { force, force };
			Spawner::m_enemies[i]->setCoords(tmp);
			tmp = { -force, -force };
			Spawner::m_enemies[j]->setCoords(tmp);

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


