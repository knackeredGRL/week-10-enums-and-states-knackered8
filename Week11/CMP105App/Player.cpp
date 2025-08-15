#include "Player.h"

Player::Player(Input* in, sf::RenderTexture* rt)
{
	setInput(in);
	setRenderTexture(rt);
	Setup();

	// initialise gravity value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform)
	m_scale = 200.0f;
	m_gravity = sf::Vector2f(0, 9.8f) * m_scale;

}

Player::~Player()
{
}

void Player::update(float dt)
{
	setWindowSize();


	m_current_position = getPosition();


	//m_direction = sf::Vector2f(2, 3);
	m_direction = VectorHelper::normalise(m_direction);
	m_velocity = (m_direction * m_speed);
	//setPosition(getPosition() + (m_velocity * dt));

	// Apply gravity force, increasing velocity
// Move shape by new velocity
	sf::Vector2f m_gravity_power = m_stepVelocity * dt + 0.5f * m_gravity * dt * dt; //ut + 1/2at^2
	m_stepVelocity += m_gravity * dt; // v = u + at note the += is not =
	//setPosition(getPosition() + m_gravity_power);
	setPosition(getPosition() + (m_velocity * dt) + m_gravity_power);
	// Check for collision with bottom of window
	if (getPosition().y >= 1080)
	{
		//setPosition(getPosition().x, 1080);
		//m_stepVelocity = sf::Vector2f(0, 0);
	}


	m_collisionBox = getGlobalBounds();

	CheckScreenCollision(dt);
}

void Player::handleInput(float dt)
{
	/*m_direction.y = (input->isPressed(sf::Keyboard::Up) * -1) + input->isPressed(sf::Keyboard::Down);
	m_direction.x = (input->isPressed(sf::Keyboard::Left) * -1) + input->isPressed(sf::Keyboard::Right);*/

	//m_direction.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) * -1) + sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
	m_direction.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) * -1) + sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

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
	if (m_collisionBox.contains(m_current_position.x, m_screen_height))
	{
		m_stepVelocity = sf::Vector2f(0, 0);
		m_direction.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) * -1) + (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) * 0);


	}
	if (m_collisionBox.contains(m_current_position.x, 0))
	{

		m_direction.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) * 0) + sf::Keyboard::isKeyPressed(sf::Keyboard::Down);


	}

}

void Player::SetStepVelocity(const sf::Vector2f& sv)
{
	m_stepVelocity = sv;
}
