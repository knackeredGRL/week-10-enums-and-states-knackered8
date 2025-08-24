#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
class Bullet;
class ShootPointer;


class BulletManager : public BaseLevel
{
public:
	BulletManager(Input* in, sf::RenderTexture* rt, ShootPointer* shootPointer);
	virtual ~BulletManager();

	//updates bullets and removes from active pool if not alive
	void update(float dt);

	//adds single bullet from inactive to active pool when called
	Bullet* GetBullet(const sf::Vector2f& direction, const sf::Vector2f& pos);

	void RenderBullets();

	std::vector<Bullet*>& GetActivePool()
	{
		return m_active;
	}

	void handleInput(float dt);

	void render();

	void ResetAllBullets();

	void SetCanShoot(const bool& shoot) { canShoot = shoot; }



private:
	std::vector<Bullet*> m_active;
	Bullet* m_pool;
	unsigned int m_poolSizeMax = 100;
	sf::Texture* m_texture;
	ShootPointer* m_shootPointer;
	sf::Vector2f m_direction;
	float m_shootTimer = 0;
	bool canShoot = true;
};

