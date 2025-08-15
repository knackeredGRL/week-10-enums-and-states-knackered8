#pragma once
#include "Framework/GameObject.h"


class Player :public GameObject
{
public:
	Player(Input* in, sf::RenderTexture* rt);
	~Player();
	void update(float dt );
	void handleInput(float dt);
	void render();
	void Setup();

	//stops player from moving past screen coordinatesS
	void CheckScreenCollision(const float& dt);
	void SetStepVelocity(const sf::Vector2f& sv);
	void CheckGroundCollision(const float& dt);
	sf::Vector2f CalculateGravity(const float& dt, sf::Vector2f& stepVelocity, sf::Vector2f& gravity);
	sf::Vector2f CalculateVelocity(const float& dt, sf::Vector2f& direction);



private:
	float m_speed = 100;
	float m_acceleration = 2000.f;
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	float m_scale = 200.f;
	sf::Vector2f m_gravity = sf::Vector2f(0, 0);
	sf::Vector2f m_stepVelocity = sf::Vector2f(0, 0);
	bool m_isJumping = false;
	sf::Vector2f m_jumpVector;
	int m_jumping = 0;


};

