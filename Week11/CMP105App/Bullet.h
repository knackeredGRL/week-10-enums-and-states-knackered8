#pragma once
#include "Framework/GameObject.h"
class Bullet : public GameObject
{
public:
	Bullet(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, sf::Texture* texture);

	Bullet();

	~Bullet();

	void update(float dt);

	void handleInput(float dt);

	void render();

	void ResetBullet();

	void SetDirection(const sf::Vector2f& direction);


private:
	float m_speed = 500;
};

