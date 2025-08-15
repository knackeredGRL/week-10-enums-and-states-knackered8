#pragma once
#include "Framework/GameObject.h"
class Bullet : public GameObject
{
public:
	Bullet(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position);

	~Bullet();

	void update(float dt);

	void handleInput(float dt);

	void render();


private:
	float m_speed = 500;




};

