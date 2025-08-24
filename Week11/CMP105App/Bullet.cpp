#include "Bullet.h"

Bullet::Bullet(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture)
{
	setInput(in);
	setRenderTexture(rt);
	//Setup("gfx/Mushroom.png", false, sf::IntRect(0, 0, 32, 32), sf::Vector2f(100, 100), sf::Vector2f(16, 16));

	setSize(sf::Vector2f(16, 16));
	setOrigin(sf::Vector2f(16, 16) / 2.f);
	setTexture(texture);
	setTextureRect(sf::IntRect(10,68,5,10));
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
	colTest.setFillColor(sf::Color::White);
	colTest.setPosition(m_collisionBox.left, m_collisionBox.top);
	colTest.setSize(sf::Vector2f(m_collisionBox.width, m_collisionBox.height));


	m_direction = VectorHelper::normalise(m_direction);
	m_velocity = (m_direction * m_speed);
	setPosition(getPosition() +(m_velocity* dt));

	setRotation(((atan2(m_direction.y, m_direction.x)) * 180 / 3.14159) + 90);

	if (isAlive())
	{
		m_lifeTimer += dt;
	}

	if (m_lifeTimer >= 2)
	{
		setAlive(false);
	}


	m_collisionBox = getGlobalBounds();

}

void Bullet::handleInput(float dt)
{
}

void Bullet::render()
{
	m_rt->draw(*this);
	//m_rt->draw(colTest);
}

void Bullet::ResetBullet()
{
	m_lifeTimer = 0;
}


