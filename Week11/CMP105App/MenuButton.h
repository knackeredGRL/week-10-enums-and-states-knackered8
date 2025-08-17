#pragma once
#include "Framework/Gameobject.h"
#include "SFML\Graphics.hpp"
#include "Framework//BaseLevel.h"
class GameState;
class Controls;
#include "Framework/AudioManager.h"

enum class ButtonType
{
	Start,
	Controls,
	Exit
};



class MenuButton : public GameObject
{
public:
	MenuButton(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture,sf::Vector2f size, sf::Vector2f position , std::string buttonString, ButtonType buttonType, int charSize, Controls* controls);
	~MenuButton();


	void update(float dt);

	void handleInput(float dt);

	void render();

	void SetControlsDisplayed(const bool& conDis) { m_controlsDisplayed = conDis; }


private:
	sf::Font m_mmFont;
	sf::Text m_mmText;
	GameState* gameState;
	ButtonType m_buttonType;
	int m_characterSize=0;
	Controls* m_controls;
	bool m_controlsDisplayed = false;
	AudioManager* m_audioManager;
};

