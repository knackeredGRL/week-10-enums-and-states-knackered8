#include "PlayerTopDown.h"


PlayerTopDown::PlayerTopDown(Input* in, sf::RenderTexture* rt)
{
	setInput(in);
	setRenderTexture(rt);
	Setup("gfx/BalloonerSpriteSheet.png", true, sf::IntRect(0, 0, 28, 37), sf::Vector2f(100, 100), sf::Vector2f(100, 100));
}

PlayerTopDown::~PlayerTopDown()
{
}

void PlayerTopDown::update(float dt)
{
	setWindowSize();
	m_current_position = getPosition();

	setPosition(getPosition() + (CalculateVelocity(dt, m_direction) * dt));


	if (m_invincibe)
	{
		m_invincibleTimer += dt;
	}

	if (m_invincibleTimer >= 2)
	{
		m_invincibe = false;
		m_invincibleTimer = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		setScale(-1.0f, 1.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		setScale(1.0f, 1.0f);
	}
}

void PlayerTopDown::handleInput(float dt)
{
	m_direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::A) * -1) + sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	m_direction.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::W) * -1) + sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

void PlayerTopDown::render()
{
}


