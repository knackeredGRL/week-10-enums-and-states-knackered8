#pragma once
#include "SFML\Graphics.hpp"
#include "Framework//BaseLevel.h"
class GameState;
class MenuButton;
class Controls;


class MainMenu : public BaseLevel
{
public:
	MainMenu(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture);
	~MainMenu();

	void update(float dt);

	void handleInput(float dt);

	void render();

	void onBegin();
	void onEnd();


private:
	sf::Font m_mmFont;
	sf::Text m_mmText;
	MenuButton* m_startButton;
	MenuButton* m_controlsButton;
	MenuButton* m_exitButton;
	Controls* m_controls;
	//GameState* gameState;
	


};

