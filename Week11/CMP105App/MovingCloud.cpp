#include "MovingCloud.h"

MovingCloud::MovingCloud(Input* in, sf::RenderTexture* rt, sf::Vector2f size, sf::Vector2f position, std::string textureString)
{
	setInput(in);
	setRenderTexture(rt);
	Setup(textureString, true, sf::IntRect(0, 37, 62, 30), position, size);

	m_direction = sf::Vector2f(-10, 0);
	m_start_position = sf::Vector2f(2220, position.y);
}

MovingCloud::MovingCloud()
{
}

MovingCloud::~MovingCloud()
{
}

void MovingCloud::update(float dt)
{

	m_direction = VectorHelper::normalise(m_direction);
	m_velocity = (m_direction * m_speed);
	setPosition(getPosition() + (m_velocity * dt));

	m_collisionBox = getGlobalBounds();

	if (m_collisionBox.contains(-400, getPosition().y))
	{
		setPosition(m_start_position);
		


	}




}

void MovingCloud::render()
{
	m_rt->draw(*this);
}
