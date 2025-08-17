#include "MainMenu.h"
#include <iostream>
#include "MenuButton.h"
#include "controls.h"

MainMenu::MainMenu(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture)
{
	window = rw;
	gameState = gs;
	input = in;
	m_rt = renderTexture;

	m_controls = new Controls(window, input, gameState, m_rt,sf::Vector2f(800,200), sf::Vector2f(900,500));

	m_startButton = new MenuButton(window,input,gameState,m_rt,sf::Vector2f(256,128), sf::Vector2f(200, 200),"Start Button",ButtonType::Start,40,m_controls);
	m_controlsButton = new MenuButton(window, input, gameState, m_rt, sf::Vector2f(256, 128), sf::Vector2f(200, 500), "Controls Button", ButtonType::Controls,30, m_controls);

	m_exitButton = new MenuButton(window, input, gameState, m_rt, sf::Vector2f(256, 128), sf::Vector2f(200, 800), "Exit Button", ButtonType::Exit,46, m_controls);

	if (!m_mmFont.loadFromFile("font/editundo.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}

	m_mmText.setFont(m_mmFont); // font is a sf::Font

	// set the string to display
	m_mmText.setString("BALLOONER");

	// set the character size
	m_mmText.setCharacterSize(96); // in pixels, not points!

	// set the color
	m_mmText.setFillColor(sf::Color::White);

	m_mmText.setPosition(1000, 300);

	if (!m_cloudTexture.loadFromFile("gfx/BalloonerSpriteSheet.png"))
	{
		std::cout << "player texture didnt load correctly" << std::endl;
	}

	if (!m_balloonTexture.loadFromFile("gfx/BalloonerSpriteSheet.png"))
	{
		std::cout << "player texture didnt load correctly" << std::endl;
	}

	cloud.setTexture(&m_cloudTexture);
	cloud.setTextureRect(sf::IntRect(0, 37, 62, 30));
	cloud.setSize(sf::Vector2f(400,200));
	cloud.setPosition(sf::Vector2f(500, 500));

	cloud1.setTexture(&m_cloudTexture);
	cloud1.setTextureRect(sf::IntRect(0, 37, 62, 30));
	cloud1.setSize(sf::Vector2f(400, 200));
	cloud1.setPosition(sf::Vector2f(1500, 200));

	cloud2.setTexture(&m_cloudTexture);
	cloud2.setTextureRect(sf::IntRect(0, 37, 62, 30));
	cloud2.setSize(sf::Vector2f(400, 200));
	cloud2.setPosition(sf::Vector2f(1400, 800));

	balloon.setTexture(&m_balloonTexture);
	balloon.setTextureRect(sf::IntRect(31, 0, 16, 33));
	balloon.setSize(sf::Vector2f(400, 400));
	balloon.setPosition(sf::Vector2f(1000, 400));

	m_audioManager = new AudioManager();

	m_audioManager->addMusic("sfx/retro-game-music-245230.ogg", "music");

}

MainMenu::~MainMenu()
{
}

void MainMenu::handleInput(float dt)
{
	m_startButton->handleInput(dt);
	m_controlsButton->handleInput(dt);
	m_exitButton->handleInput(dt);
}

void MainMenu::update(float dt)
{
	/*if (input->isPressed(sf::Keyboard::Space))
	{
		gameState->setCurrentState(State::LEVEL);
	}*/
	m_startButton->update(dt);
	m_controlsButton->update(dt);
	m_exitButton->update(dt);
}

void MainMenu::render()
{
	beginDraw();

	//m_rt->draw(m_mmText);
	m_startButton->render();
	m_rt->draw(cloud);
	m_rt->draw(cloud1);
	m_rt->draw(cloud2);
	m_rt->draw(balloon);
	m_rt->draw(m_mmText);
	m_controlsButton->render();
	m_exitButton->render();
	m_controls->render();

	endDraw();

}


void MainMenu::onBegin()
{
	m_controlsButton->SetControlsDisplayed(false);
	m_controls->setAlive(false);

}

void MainMenu::onEnd()
{



}


