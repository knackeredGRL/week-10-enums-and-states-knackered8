#include "Bullet.h"

Bullet::Bullet(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture)
{
	setInput(in);
	setRenderTexture(rt);
	//Setup("gfx/Mushroom.png", false, sf::IntRect(0, 0, 32, 32), sf::Vector2f(100, 100), sf::Vector2f(16, 16));

	setSize(sf::Vector2f(16, 16));
	setOrigin(sf::Vector2f(16, 16) / 2.f);
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

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::update(float dt)
{
	m_direction = VectorHelper::normalise(m_direction);
	m_velocity = (m_direction * m_speed);
	setPosition(getPosition() +(m_velocity* dt));

	if (isAlive())
	{
		m_lifeTimer += dt;
	}

	if (m_lifeTimer >= 2)
	{
		setAlive(false);
	}

}

void Bullet::handleInput(float dt)
{
}

void Bullet::render()
{
	m_rt->draw(*this);
}

void Bullet::ResetBullet()
{
	m_lifeTimer = 0;


}

void Bullet::SetDirection(const sf::Vector2f& direction)
{
	m_direction = direction;
}
