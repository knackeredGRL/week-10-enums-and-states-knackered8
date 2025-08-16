#include "ShootPointer.h"
#include "Player.h"
#include "Bullet.h"

ShootPointer::ShootPointer(Input* in, sf::RenderTexture* rt, Player* pl)
{
	setInput(in);
	setRenderTexture(rt);
	Setup("gfx/icon.png", false, sf::IntRect(0, 0, 32, 32), sf::Vector2f(100, 100), sf::Vector2f(16, 16));

	m_playerPTR = pl;

}

ShootPointer::~ShootPointer()
{



}

void ShootPointer::update(float dt)
{
	//setPosition(m_playerPTR->getPosition().x, m_playerPTR->getPosition().y -40.f);

	m_tempPos = getPosition();
	m_direction = FindMousePosition() - m_playerPTR->getPosition();
	m_direction = VectorHelper::normalise(m_direction);
	std::cout << m_direction.x <<std::endl;
	std::cout << m_direction.y << std::endl;
	setPosition(m_playerPTR->getPosition() + (m_direction *50.f));
	



	if (VectorHelper::magnitude(FindMousePosition() -m_playerPTR->getPosition()) <= 50.f)
	{
		//setPosition(m_tempPos);
	}



	/*for (int i = 0; i < m_bullet_vector.size(); i++)
	{
		m_bullet_vector[i]->update(dt);
	}*/

}

void ShootPointer::handleInput(float dt)
{
	/*if (input->isLeftMousePressed())
	{
		m_bullet = new Bullet(input, m_rt, m_direction,getPosition());
		m_bullet_vector.push_back(m_bullet);

	}*/


}

void ShootPointer::render()
{
	/*for (int i = 0; i < m_bullet_vector.size(); i++)
	{
		m_rt->draw(*m_bullet_vector[i]);
	}*/

}

sf::Vector2f ShootPointer::FindMousePosition()
{
	m_mousePos.x = input->getMouseX();
	m_mousePos.y = input->getMouseY();

	return m_mousePos;
}
