// Game Object Class
// A class representing a single renderable game object.
// Game Object extend sf::RectangleShape, and added functionailty for collision, sprite states (alive/dead), velocity for movement, input component
// Most elements of your game will extend game object to create larger more complex elements such as player, enemies, bullets etc.
// @author paul Robertson

#pragma once
#include "SFML\Graphics.hpp"
#include "Input.h"
#include "iostream"

class GameObject : public sf::RectangleShape
{
public:
	GameObject();
	~GameObject();

	// Virtual update function. Base function does nothing (for static objects). Inheritted version will most likely override this function.
	virtual void handleInput(float dt);
	virtual void update(float dt);

	// Control sprite speed and direction
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity();

	// Sprite state
	bool isAlive() { return alive; };
	void setAlive(bool b) { alive = b; };

	// For sprite collision, set collider box, get collider box, and dedicated virtual function for collision response
	bool isCollider() { return collider; };
	void setCollider(bool b) { collider = b; };
	sf::FloatRect getCollisionBox();
	void setCollisionBox(float x, float y, float width, float height) { collisionBox = sf::FloatRect(x, y, width, height); };
	void setCollisionBox(sf::FloatRect fr) { collisionBox = fr; };
	virtual void collisionResponse(GameObject* collider);

	// Set the input component
	void setInput(Input* in) { input = in; };
	void setWindow(sf::RenderWindow* win) { window = win; };
	void setRenderTexture(sf::RenderTexture* rt) { m_rt = rt; };

protected:
	// Sprite properties
	sf::Vector2f velocity;
	bool alive;

	// Collision vars
	sf::FloatRect collisionBox;
	bool collider;

	// input component
	Input* input;
	sf::RenderWindow* window;
	sf::RenderTexture* m_rt;

	sf::Texture* m_texture = nullptr;

	sf::Vector2f m_start_position = sf::Vector2f(100, 100);
	sf::Vector2f m_start_size = sf::Vector2f(100, 100);
	sf::Vector2f m_current_position = sf::Vector2f(100, 100);

};