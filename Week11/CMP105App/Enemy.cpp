#include "Enemy.h"

Enemy::Enemy(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture)
{
	setInput(in);
	setRenderTexture(rt);
	//Setup("gfx/Mushroom.png", false, sf::IntRect(0, 0, 32, 32), sf::Vector2f(100, 100), sf::Vector2f(16, 16));

	setSize(sf::Vector2f(32, 32));
	setOrigin(sf::Vector2f(32, 32) / 2.f);
	setTexture(texture);
	m_texture = texture;


	//if (isSpriteSheet)
	//{
	//setTextureRect(intRect);
	//}

	setPosition(sf::Vector2f(100, 100));




	m_direction = direction;
	m_current_position = position;

	setPosition(m_current_position);

	m_alive = false;

}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	m_collisionBox = getGlobalBounds();

	m_direction = VectorHelper::normalise(m_direction);
	m_velocity = (m_direction * m_speed);
	setPosition(getPosition() + (m_velocity * dt));


	if (isAlive())
	{
		m_lifeTimer += dt;
	}

	if (m_lifeTimer >= 10)
	{
		setAlive(false);
	}

}

void Enemy::handleInput(float dt)
{
}

void Enemy::render()
{
	m_rt->draw(*this);
}

void Enemy::ResetEnemy()
{
	m_lifeTimer = 0;
}

//float& Enemy::TakeDamage(float& health, const float& damage)
//{
//	// TODO: insert return statement here
//	return;
//}
//
//void Enemy::OnOutsideBounds()
//{
//}
//
//const bool& Enemy::CheckCollisionArea(const sf::FloatRect& floatRect)
//{
//	// TODO: insert return statement here
//}
