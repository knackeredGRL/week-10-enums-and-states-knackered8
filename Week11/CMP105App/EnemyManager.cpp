#include "EnemyManager.h"
#include "Enemy.h"
#include "ShootPointer.h"

EnemyManager::EnemyManager(Input* in, sf::RenderTexture* rt)
{
	srand(time(0));
	input = in;
	m_rt = rt;

	m_texture = new sf::Texture();

	if (!m_texture->loadFromFile("gfx/Mushroom.png"))
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
		new (&m_pool[i]) Enemy(input, m_rt, sf::Vector2f(0, 0), sf::Vector2f(0, 0), m_texture);
	}
}

EnemyManager::~EnemyManager()
{
}

Enemy* EnemyManager::GetEnemy(const sf::Vector2f& direction, const sf::Vector2f& pos)
{


	for (int i = 0; i < m_poolSizeMax; i++)
	{

		//m_randomNum = rand() % 1000;

		//int randNum = rand() % (max - min + 1) + min;

		if (m_pool[i].isAlive())
		{
			continue;
		}
		m_pool[i].setPosition(pos);
		m_pool[i].SetDirection(direction);
		m_pool[i].setAlive(true);
		m_pool[i].ResetEnemy();
		m_active.push_back(&m_pool[i]);
		return &m_pool[i];
	}
	m_pool[0].setPosition(pos);
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

	if (m_spawnTimer >= 1)
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

