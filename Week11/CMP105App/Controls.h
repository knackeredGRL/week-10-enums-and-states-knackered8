#pragma once
#include "Framework/GameObject.h"
#include "Framework/BaseLevel.h"
class Controls : public GameObject
{
public:
	
	Controls(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture, sf::Vector2f size, sf::Vector2f position);
	Controls();
	~Controls();


	void update(float dt);

	void handleInput(float dt);

	void render();


private:
	sf::Font m_mmFont;
	sf::Text m_mmText;
	GameState* gameState;
	int m_characterSize = 0;
	





};

