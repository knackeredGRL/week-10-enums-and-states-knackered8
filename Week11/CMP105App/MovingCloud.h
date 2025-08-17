#pragma once
#include "Framework/GameObject.h"
class MovingCloud : public GameObject
{
public:
	MovingCloud(Input* in, sf::RenderTexture* rt, sf::Vector2f size, sf::Vector2f position, std::string textureString);
	MovingCloud();

	~MovingCloud();

	void update(float dt);

	void render();

private:
	sf::Vector2f m_start_position;
	float m_speed = 70;



};

