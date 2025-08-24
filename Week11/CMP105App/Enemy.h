#pragma once
#include "Framework/GameObject.h"
class Enemy : public GameObject
{
public:
	Enemy(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture);

	Enemy();

	~Enemy();

	void update(float dt);

	void handleInput(float dt);

	void render();



	//resets death timer
	void ResetEnemy();


	float& TakeDamage(float& health, const float& damage);


	//on reaching outside bounds set active to false and decrease score by 1
	void OnOutsideBounds();

	const sf::FloatRect& GetNoObstacleArea()
	{
		//return m_noObstacleArea;
	}

	const bool& CheckCollisionArea(const sf::FloatRect& floatRect);


	void SetTempPosition(const sf::Vector2f& tempPos)
	{
		m_tempPosition = tempPos;
	}

	/*const sf::FloatRect& GetCollisionBox()
	{
		return m_collisionBox;
	}*/

private:
	float m_health = 3;
	float m_speed = 100;
	float m_lifeTimer = 0;
	bool m_lifeTimerEnded = false;
	sf::Vector2f m_offset = sf::Vector2f(0, 0);
	sf::Vector2f m_tempPosition = sf::Vector2f(0,0);
	float m_elaspsedTime = 0;
	sf::RectangleShape colTest;
};

