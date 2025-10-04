#include "NPC.h"
#include "TextBox.h"
#include "PlayerTopDown.h"

NPC::NPC(Input* in, sf::RenderTexture* rt, sf::RenderWindow* hwnd, sf::Vector2f direction, sf::Vector2f position, sf::Vector2f size, std::string texture)
{
	setInput(in);
	setRenderTexture(rt);
	setWindow(hwnd);

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
	m_txtBox = std::make_unique<TextBox>(in, rt, sf::Vector2f(hwnd->getSize().x, 300), sf::Vector2f(hwnd->getSize().x / 2, 880), "gfx/BalloonerSpriteSheet.png");
	Setup(texture, true, sf::IntRect(0, 37, 62, 30), position, size);

	//m_txtBox = new TextBox(in, rt, sf::Vector2f(hwnd->getSize().x, 300), sf::Vector2f(hwnd->getSize().x / 2, 880), "gfx/BalloonerSpriteSheet.png");
}

NPC::NPC()
{
}

NPC::~NPC()
{
}

void NPC::update(float dt, const sf::FloatRect& otherCol)
{
	m_collisionBox = getGlobalBounds();
	setCollisionBox(m_collisionBox);
	m_txtBox->update(dt);
	
	Collision(otherCol);
	
	//m_tempPosition.x += 100 * cos(m_elaspsedTime) * dt;


	m_direction = VectorHelper::normalise(m_direction);

	
	//m_direction.x = log10(m_direction.x);
	//m_direction.y = log10(m_direction.y);
	
	//m_tempPosition.x = log10(m_tempPosition.x);
	//m_tempPosition.y = log10(m_tempPosition.y);
	

	//std::cout << " NPC collider X " << GetCollisionBox().left<< " NPC collider Y " << GetCollisionBox().top<<std::endl;





}

void NPC::handleInput(float dt)
{
}

void NPC::render()
{
	m_rt->draw(*this);
	m_txtBox->render();
}

void NPC::Collision(const sf::FloatRect& otherCollider)
{
	//std::cout << GetCollisionBox().intersects(otherCollider) << std::endl;
	if (GetCollisionBox().intersects(otherCollider) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_txtBox->SetVisible(true);
		
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && m_txtBox->GetVisible() == true)
		{
			m_txtBox->SetVisible(false);
		}
	}

	

}
