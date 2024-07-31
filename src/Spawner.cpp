#include "Spawner.h"
#include "Presenter.h"
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
	m_enemy.rect.y = 0;
	m_enemy.texture = loadTexture(enemyTexture);
	for (int i = 0; i < m_enemyAmount; i++) {
		m_enemy.rect.x = rand() % Presenter::m_SCREEN_WIDTH;
		Enemy _Enemy;

		_Enemy.init(m_enemy, m_enemyVelocity, 270);
		//cout << "\n _Enemy.w: " << m_enemy.rect.x;
		m_enemies.push_back(_Enemy);
	}
}

void Spawner::update(float2 playerPos)
{
	for (int i = 0; i < m_enemyAmount; i++) {
		m_enemies[i].update(playerPos);
		/*cout << "\n m_enemies[" << i << "].w: " << m_enemies[i].getRect().x;
		cout << "\n m_enemies[" << i << "].w: " << m_enemies[i].getRect().y;
		cout << "\n m_enemies[" << i << "].w: " << m_enemies[i].getRect().w;
		cout << "\n m_enemies[" << i << "].w: " << m_enemies[i].getRect().h;*/
		
	}
		//SDL_Delay(9999999);
}

void Spawner::draw()
{
	for (int i = 0; i < m_enemyAmount; i++) {
		m_enemies[i].draw();
	}
	
}

void Spawner::destroy()
{
	SDL_DestroyTexture(m_enemy.texture);
}


