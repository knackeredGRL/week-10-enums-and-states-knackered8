#include "Player.h"

Player::Player(Input* in, sf::RenderTexture* rt)
{
	setInput(in);
	setRenderTexture(rt);
	Setup();


}

Player::~Player()
{
}

void Player::update(float dt)
{

	m_current_position = getPosition();

	m_acceleration = 2.f;
	m_direction = sf::Vector2f(2, 3);
	m_direction = VectorHelper::normalise(m_direction);
	m_velocity += (m_direction * m_acceleration) * dt;
	setPosition(getPosition() + (m_velocity * dt));

}

void Player::handleInput(float dt)
{
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
