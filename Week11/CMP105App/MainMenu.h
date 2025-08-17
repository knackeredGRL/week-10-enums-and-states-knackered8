#pragma once
#include "SFML\Graphics.hpp"
#include "Framework//BaseLevel.h"
#include "Framework//GameObject.h"
class GameState;
class MenuButton;
class Controls;
#include "Framework//AudioManager.h"


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
	GameObject cloud;
	GameObject cloud1;
	GameObject cloud2;
	GameObject balloon;
	sf::Texture m_cloudTexture;
	sf::Texture m_balloonTexture;
	//GameState* gameState;
	AudioManager* m_audioManager;


};

