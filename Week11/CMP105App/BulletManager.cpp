#include "BulletManager.h"
#include "Bullet.h"
#include "ShootPointer.h"

BulletManager::BulletManager(Input* in, sf::RenderTexture* rt, ShootPointer* shootPointer)
{
	input = in;
	m_rt = rt;
	m_shootPointer = shootPointer;

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

	m_pool = new Bullet[100];
	for (int i = 0; i < m_poolSizeMax; i++) {
		new (&m_pool[i]) Bullet(input, m_rt, sf::Vector2f(0, 0), sf::Vector2f(0, 0),m_texture);
	}
}

BulletManager::~BulletManager()
{
}

Bullet* BulletManager::GetBullet(const sf::Vector2f& direction, const sf::Vector2f& pos)
{
	for (int i = 0; i < m_poolSizeMax; i++)
	{

		if (m_pool[i].isAlive())
		{
			continue;
		}
		m_pool[i].setPosition(pos);
		m_pool[i].SetDirection(direction);
		m_pool[i].setAlive(true);
		m_pool[i].ResetBullet();
		m_active.push_back(&m_pool[i]);
		return &m_pool[i];
	}
	m_pool[0].setPosition(pos);
	m_pool[0].SetDirection(direction);
	m_pool[0].ResetBullet();
	return &m_pool[0];
}

void BulletManager::update(float dt)
{
	for (int i = m_active.size() - 1; i >= 0; i--)
	{
		m_active[i]->update(dt);

		if (!m_active[i]->isAlive())
		{
			m_active.erase(m_active.begin() + i);
		}
	}

	if (!canShoot)
	{
		m_shootTimer += dt;
	}

	if (m_shootTimer >= 1)
	{
		canShoot = true;
		m_shootTimer = 0;
	}


}

void BulletManager::RenderBullets()
{
	for (auto& i : m_active) {
		i->render();
	}
}

void BulletManager::handleInput(float dt)
{
	if (input->isLeftMousePressed() &&canShoot)
	{
		GetBullet(m_shootPointer->GetDirection(), m_shootPointer->getPosition());
		canShoot = false;
		//m_bullet = new Bullet(input, m_rt, m_direction, getPosition());
		//m_bullet_vector.push_back(m_bullet);

	}


}

void BulletManager::render()
{
}

void BulletManager::ResetAllBullets()
{
	for (int i = m_active.size() - 1; i >= 0; i--)
	{
		m_active.erase(m_active.begin() + i);
	}


}
