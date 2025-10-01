#include "NPC.h"

NPC::NPC(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, std::string texture)
{
	setInput(in);
	setRenderTexture(rt);
	////Setup("gfx/Mushroom.png", false, sf::IntRect(0, 0, 32, 32), sf::Vector2f(100, 100), sf::Vector2f(16, 16));

	//setSize(sf::Vector2f(64, 64));
	//setOrigin(sf::Vector2f(64, 64) / 2.f);
	//setTexture(texture);
	//setTextureRect(sf::IntRect(31, 0, 16, 33));
	//m_texture = texture;


	//if (isSpriteSheet)
	//{
	//setTextureRect(intRect);
	//}

	//setPosition(sf::Vector2f(100, 100));




	/*m_direction = direction;
	m_current_position = position;

	setPosition(m_current_position);

	m_alive = false;*/


	//m_offset = position;
	//m_tempPosition = position;

	Setup(texture, true, sf::IntRect(0, 37, 62, 30), position, sf::Vector2f(64, 64));
}

NPC::NPC()
{
}

NPC::~NPC()
{
}

void NPC::update(float dt)
{
	m_collisionBox = getGlobalBounds();

	

	
	//m_tempPosition.x += 100 * cos(m_elaspsedTime) * dt;


	m_direction = VectorHelper::normalise(m_direction);

	
	//m_direction.x = log10(m_direction.x);
	//m_direction.y = log10(m_direction.y);
	
	//m_tempPosition.x = log10(m_tempPosition.x);
	//m_tempPosition.y = log10(m_tempPosition.y);
	







}

void NPC::handleInput(float dt)
{
}

void NPC::render()
{
	m_rt->draw(*this);
}
