#include "MenuButton.h"
#include "controls.h"

MenuButton::MenuButton(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture, sf::Vector2f size, sf::Vector2f position, std::string buttonString, ButtonType buttonType, int charSize, Controls* controls)
{
	window = rw;
	gameState = gs;
	input = in;
	m_rt = renderTexture;
	m_buttonType = buttonType;
	m_characterSize = charSize;
	m_controls = controls;

	if (!m_mmFont.loadFromFile("font/editundo.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}

	m_mmText.setFont(m_mmFont); // font is a sf::Font

	// set the string to display
	m_mmText.setString(buttonString);

	// set the character size
	m_mmText.setCharacterSize(m_characterSize); // in pixels, not points!
	
	// set the color
	m_mmText.setFillColor(sf::Color::White);

	

	setSize(size);
	setOrigin(size / 2.f);
	

	setPosition(position);

	setFillColor(sf::Color::Black);

	m_mmText.setPosition((position- size/2.f) +sf::Vector2f(10,35));

	m_audioManager = new AudioManager();



	m_audioManager->addSound("sfx/click-345983.ogg", "click");
	m_audioManager->addMusic("sfx/retro-game-music-245230.ogg", "music");
	

}

MenuButton::~MenuButton()
{
}

void MenuButton::handleInput(float dt)
{

	if (m_collisionBox.contains(sf::Vector2f(input->getMouseX(), input->getMouseY())) && input->isLeftMousePressed())
	{
		m_audioManager->playSoundbyName("click");
		m_audioManager->getSound("click")->play();
		switch (m_buttonType)
		{
		case ButtonType::Start:
			gameState->setCurrentState(State::LEVEL);
			m_audioManager->playMusicbyName("music");
			
			break;

		case ButtonType::Controls:
			if (!m_controlsDisplayed)
			{
				m_controls->setAlive(true);
				m_controlsDisplayed = true;
			}
			else
			{
				m_controls->setAlive(false);
				m_controlsDisplayed = false;
			}

			

			break;

		case ButtonType::Exit:
			window->close();

			break;

		}


	}
}

void MenuButton::update(float dt)
{
	m_collisionBox = getGlobalBounds();

	if (gameState->getCurrentState() == State::MENU)
	{
		m_audioManager->stopAllMusic();
	}


}

void MenuButton::render()
{
	//beginDraw();
	m_rt->draw(*this);
	m_rt->draw(m_mmText);

	//endDraw();

}

