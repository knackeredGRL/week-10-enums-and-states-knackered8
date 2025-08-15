#pragma once
#include "SFML\Graphics.hpp"
#include "Framework//BaseLevel.h"
class GameState;


class MainMenu : public BaseLevel
{
public:
	MainMenu(sf::RenderWindow* rw, Input* in, GameState* gs);
	~MainMenu();

	void update(float dt);

	void handleInput(float dt);

	void render();


private:
	sf::Font m_mmFont;
	sf::Text m_mmText;
	//GameState* gS;



};

