#include "Enemy.h"

Enemy::Enemy(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture)
{
	setInput(in);
	setRenderTexture(rt);
	//Setup("gfx/Mushroom.png", false, sf::IntRect(0, 0, 32, 32), sf::Vector2f(100, 100), sf::Vector2f(16, 16));

	setSize(sf::Vector2f(64, 64));
	setOrigin(sf::Vector2f(64, 64) / 2.f);
	setTexture(texture);
	setTextureRect(sf::IntRect(31,0,16,33));
	m_texture = texture;


	//if (isSpriteSheet)
	//{
	//setTextureRect(intRect);
	//}

	//setPosition(sf::Vector2f(100, 100));




	m_direction = direction;
	m_current_position = position;

	setPosition(m_current_position);

	m_alive = false;


	m_offset = position;
	m_tempPosition = position;

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

	colTest.setFillColor(sf::Color::White);
	colTest.setPosition(m_collisionBox.left, m_collisionBox.top);
	colTest.setSize(sf::Vector2f(m_collisionBox.width, m_collisionBox.height));
	
	m_elaspsedTime += dt;
	m_tempPosition.y += 100* sin(m_elaspsedTime*3) *dt;
	//m_tempPosition.x += 100 * cos(m_elaspsedTime) * dt;
	

	m_direction = VectorHelper::normalise(m_direction);

	m_rotation = (atan2(m_direction.y, m_direction.x))*180.f /PI +90;
	setRotation(m_rotation);
	//m_direction.x = log10(m_direction.x);
	//m_direction.y = log10(m_direction.y);
	m_velocity = (m_direction * m_speed);
	m_tempPosition += (m_velocity * dt);
	//m_tempPosition.x = log10(m_tempPosition.x);
	//m_tempPosition.y = log10(m_tempPosition.y);
	setPosition(m_tempPosition);




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
	//m_rt->draw(colTest);
}

void Enemy::ResetEnemy()
{
	m_lifeTimer = 0;
}

//float& Enemy::TakeDamage(float& health, const float& damage)
//{
//	// TODO: insert return statement here
//	return;
//
//
//void Enemy::OnOutsideBounds()
//{
//}
//
//const bool& Enemy::CheckCollisionArea(const sf::FloatRect& floatRect)
//{
//	// TODO: insert return statement here
//}
