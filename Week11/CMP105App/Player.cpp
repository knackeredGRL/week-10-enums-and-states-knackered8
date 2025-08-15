#include "Player.h"

Player::Player(Input* in, sf::RenderTexture* rt)
{
	setInput(in);
	setRenderTexture(rt);
	Setup();

	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	m_scale = 200.0f;
	m_gravity = sf::Vector2f(0, 9.8f) * m_scale;
	m_jumpVector = sf::Vector2f(0, -4.0f) * m_scale;

}

Player::~Player()
{
}

void Player::update(float dt)
{
	CheckScreenCollision(dt);

	setWindowSize();
	m_current_position = getPosition();

	setPosition(getPosition() + (CalculateVelocity(dt,m_direction) * dt) + CalculateGravity(dt,m_stepVelocity,m_gravity));
	// Check for collision with bottom of window
	
	m_collisionBox = getGlobalBounds();
	CheckGroundCollision(dt);

}

void Player::handleInput(float dt)
{
	
	m_direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) * -1) + sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	m_jumping = (sf::Keyboard::isKeyPressed(sf::Keyboard::W));
	// Jump, check if already jumping
	JumpCheck(m_jumping);
}

void Player::render()
{
}

void Player::Setup()
{
	m_texture = new sf::Texture();

	if (!m_texture->loadFromFile("gfx/gobsmithSpriteSheet.png"))
	{
		std::cout << "player texture didnt load correctly" << std::endl;
	}


	setSize(m_start_size);
	setOrigin(m_start_size / 2.f);
	setTexture(m_texture);
	setTextureRect(sf::IntRect(0, 0, 32, 32));
	setPosition(m_start_position);
	



}

void Player::CheckScreenCollision(const float& dt)
{

	if (m_collisionBox.contains(0, m_current_position.y))
	{

		m_direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) * 0) + sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		

	}
	if (m_collisionBox.contains(m_screen_width, m_current_position.y))
	{

		m_direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) * -1) + (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) * 0);

	}
	

}

void Player::SetStepVelocity(const sf::Vector2f& sv)
{
	m_stepVelocity = sv;
}

void Player::CheckGroundCollision(const float& dt)
{
	if (m_collisionBox.contains(m_current_position.x, m_screen_height))
	{
		m_stepVelocity = sf::Vector2f(0, 0);
		m_isJumping = false;
	}
}

sf::Vector2f Player::CalculateGravity(const float& dt, sf::Vector2f& stepVelocity, sf::Vector2f& gravity)
{
	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sf::Vector2f m_gravity_power = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut + 1/2at^2
	stepVelocity += gravity * dt; // v = u + at note the += is not =

	return m_gravity_power;
}

sf::Vector2f Player::CalculateVelocity(const float& dt, sf::Vector2f& direction)
{
	direction = VectorHelper::normalise(direction);

	m_velocity = (direction * m_speed);

	return m_velocity;
}

void Player::JumpCheck(const int& jumping)
{
	if (jumping != 1)
	{
		return;
	}

	if (m_isJumping)
	{
		return;
	}

	m_stepVelocity = m_jumpVector;
	m_isJumping = true;
}
