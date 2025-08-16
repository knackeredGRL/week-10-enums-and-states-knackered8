#include "GameObject.h"

GameObject::GameObject()
{
	input = nullptr;
	m_rt = nullptr;


}

GameObject::~GameObject()
{

}

// Override this function to provide input handling for the derived class
void GameObject::handleInput(float dt)
{
}

// override this function to provide functionality
void GameObject::update(float dt)
{
}

// Sets the velocity of the sprite
void GameObject::setVelocity(sf::Vector2f vel)
{
	m_velocity = vel;
}
void GameObject::setVelocity(float vx, float vy)
{
	m_velocity.x = vx;
	m_velocity.y = vy;
}

// get sprite velocity
sf::Vector2f GameObject::getVelocity()
{
	return m_velocity;
}

// Returns collision box + position, giving the collision box in the correct position
sf::FloatRect GameObject::getCollisionBox() {
	
	return sf::FloatRect(m_collisionBox.left + getPosition().x - getOrigin().x, m_collisionBox.top + getPosition().y - getOrigin().y, m_collisionBox.width, m_collisionBox.height); 
}

// Reponse function, what the sprite does based on collision
// Colliding object is passed in for information
// e.g. compare sprite positions to determine new velocity direction.
// e.g. checking sprite type (world, enemy, bullet etc) so response is based on that.
void GameObject::collisionResponse(GameObject * collider)
{
}

void GameObject::setWindowSize()
{
	//m_screen_width = m_rt->getSize().x;
	//m_screen_height = m_rt->getSize().y;


}

sf::Vector2f GameObject::GetStartPosition()
{
	return m_start_position;
}

const sf::Vector2f& GameObject::GetDirection()
{
	return m_direction;
}

void GameObject::Setup(const std::string& texturePath, const bool& isSpriteSheet, const sf::IntRect& intRect, const sf::Vector2f& pos, const sf::Vector2f& size)
{
	m_texture = new sf::Texture();

	if (!m_texture->loadFromFile(texturePath))
	{
		std::cout << "player texture didnt load correctly" << std::endl;
	}


	setSize(size);
	setOrigin(size / 2.f);
	setTexture(m_texture);

	if (isSpriteSheet)
	{
		setTextureRect(intRect);
	}

	setPosition(pos);




}


void GameObject::SetDirection(const sf::Vector2f& direction)
{
	m_direction = direction;
}
