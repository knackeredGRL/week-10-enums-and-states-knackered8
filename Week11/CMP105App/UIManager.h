#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameManager.h"

class UIManager
{
public:
	UIManager();
	//updates ui is bad
	void Update();
	void Render(sf::RenderTarget* rT);

private:
	std::shared_ptr<sf::Font> m_uiFont;
	sf::Text m_uiLivesNum;
	sf::Text m_uiLivesText;
	sf::Text m_uiScoreNum;
	sf::Text m_uiScoreText;
	sf::Text m_ui;
};

