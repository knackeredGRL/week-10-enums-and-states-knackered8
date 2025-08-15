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


private:
	float m_speed = 10;
	float m_acceleration = 2.f;
	sf::Vector2f m_direction = sf::Vector2f(0, 0);

};

