#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include <cstdlib>
class Enemy;


class EnemyManager : public BaseLevel
{
public:
	EnemyManager(Input* in, sf::RenderTexture* rt);
	virtual ~EnemyManager();

	//updates Enemys and removes from active pool if not alive
	void update(float dt);

	//adds single Enemy from inactive to active pool when called
	Enemy* GetEnemy(const sf::Vector2f& direction, const sf::Vector2f& pos);

	void RenderEnemys();

	std::vector<Enemy*> GetActivePool()
	{
		return m_active;
	}

	void handleInput(float dt);

	void render();

	void ResetAllEnemys();

	void SetCanSpawn(const bool& spawn) { canSpawn = spawn; }

	CalculateRandom(int& random);

private:
	std::vector<Enemy*> m_active;
	Enemy* m_pool;
	unsigned int m_poolSizeMax = 100;
	sf::Texture* m_texture;
	sf::Vector2f m_direction;
	float m_spawnTimer = 0;
	bool canSpawn = true;
	int m_randomPos = 0;
	int m_sideOfScreen = 0;
	int m_randomXPos = 0;
	int m_randomYPos = 0;

};

