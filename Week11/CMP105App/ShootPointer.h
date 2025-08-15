#pragma once
#include "Framework/GameObject.h"
class Player;



class ShootPointer : public GameObject
{
public:
	ShootPointer(Input* in, sf::RenderTexture* rt, Player* pl);

	~ShootPointer();
	void update(float dt);
	void handleInput(float dt);
	void render();
	sf::Vector2f FindMousePosition();

private:
	sf::Vector2f m_direction = sf::Vector2f(0, 0);
	sf::Vector2f m_mousePos = sf::Vector2f(0, 0);
	int m_leftMosuseClicked = 0;
	
	Player* m_playerPTR = nullptr;
	sf::Vector2f m_tempPos;

};

