#include "EnemyManager.h"
#include "Enemy.h"
#include "ShootPointer.h"

EnemyManager::EnemyManager(Input* in, sf::RenderTexture* rt)
{
	srand(time(0));
	input = in;
	m_rt = rt;

	m_texture = new sf::Texture();

	if (!m_texture->loadFromFile("gfx/BalloonerSpriteSheet.png"))
	{
		std::cout << "player texture didnt load correctly" << std::endl;
	}



	/*m_texture = std::make_shared<sf::Texture>();
	if (!m_texture->loadFromFile("Assets/Spr_TileMapTankGame.png"))
	{
		std::cout << "error texture not loaded" << std::endl;
	}*/

	m_pool = new Enemy[100];
	for (int i = 0; i < m_poolSizeMax; i++) {
		new (&(m_pool[i])) Enemy(input, m_rt, sf::Vector2f(0, 0), sf::Vector2f(0, 0), m_texture);
	}
}

EnemyManager::~EnemyManager()
{
}

Enemy* EnemyManager::GetEnemy(const sf::Vector2f& direction, const sf::Vector2f& pos)
{


	for (int i = 0; i < m_poolSizeMax; i++)
	{

		m_sideOfScreen = (rand() % 4) + 1;

		switch (m_sideOfScreen)
		{
		case(1):
			m_randomXPos = -10;
			
			m_minYPos = 50;
			m_maxYPos = 980;

			m_randomYPos = (rand() % m_maxYPos) + m_minYPos;

			break;
		case(2):
			m_minXPos = 100;
			m_maxXPos = 1820;
			m_randomYPos = -10;

			m_randomXPos = (rand() % m_maxXPos) + m_minXPos;
			break;

		case(3):
			m_randomXPos = 2020;
			m_minYPos = 50;
			m_maxYPos = 980;

			m_randomYPos = (rand() % m_maxYPos) + m_minYPos;

			break;

		case(4):
			m_minXPos = 100;
			m_maxXPos = 1820;
			m_randomYPos = 1180;

			m_randomXPos = (rand() % m_maxXPos) + m_minXPos;
			break;


		}



		//m_randomXPos = (rand() % m_maxXPos) + m_minXPos;
		//m_randomYPos = (rand() % m_maxYPos) + m_minYPos;
		m_randomXDir = rand() % (-1000 - 1000 + 1) + -1000;
		m_randomYDir = rand() % (-1000 - 1000 + 1) + -1000;
		




		if (m_pool[i].isAlive())
		{
			continue;
		}

		


		m_pool[i].setPosition(sf::Vector2f(m_randomXPos,m_randomYPos));
		m_pool[i].SetStartPosition(sf::Vector2f(m_randomXPos, m_randomYPos));
		m_pool[i].SetTempPosition(sf::Vector2f(m_randomXPos, m_randomYPos));
		m_pool[i].SetDirection(sf::Vector2f(m_randomXDir, m_randomYDir));
		m_pool[i].setAlive(true);
		m_pool[i].ResetEnemy();
		m_active.push_back(&m_pool[i]);
		return &m_pool[i];
	}
	m_pool[0].setPosition(sf::Vector2f(m_randomXPos, m_randomYPos));
	m_pool[0].SetDirection(direction);
	m_pool[0].ResetEnemy();
	return &m_pool[0];
}

void EnemyManager::update(float dt)
{
	


	for (int i = m_active.size() - 1; i >= 0; i--)
	{
		m_active[i]->update(dt);

		if (!m_active[i]->isAlive())
		{
			m_active.erase(m_active.begin() + i);
		}
	}

	if (!canSpawn)
	{
		m_spawnTimer += dt;
	}

	if (m_spawnTimer >= 0.25)
	{
		canSpawn = true;
		m_spawnTimer = 0;
	}


}

void EnemyManager::RenderEnemys()
{
	for (auto& i : m_active) {
		i->render();
	}
}

void EnemyManager::handleInput(float dt)
{
	/*if (input->isLeftMousePressed() && canShoot)
	{
		GetEnemy(m_shootPointer->GetDirection(), m_shootPointer->getPosition());
		canShoot = false;
		//m_Enemy = new Enemy(input, m_rt, m_direction, getPosition());
		//m_Enemy_vector.push_back(m_Enemy);

	}*/
	if (canSpawn)
	{
		GetEnemy(sf::Vector2f(10, 10), sf::Vector2f(10, 10));
		canSpawn = false;
	}

}

void EnemyManager::render()
{
}

void EnemyManager::ResetAllEnemys()
{
	for (int i = m_active.size() - 1; i >= 0; i--)
	{
		m_active.erase(m_active.begin() + i);
	}


}

//int& EnemyManager::CalculateRandom(int& random)
//{
//	
//}

