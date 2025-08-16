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

	m_startButton = new MenuButton(window,input,gameState,m_rt,sf::Vector2f(256,128), sf::Vector2f(200, 200),"Start Button",ButtonType::Start,46,m_controls);
	m_controlsButton = new MenuButton(window, input, gameState, m_rt, sf::Vector2f(256, 128), sf::Vector2f(200, 500), "Controls Button", ButtonType::Controls,35, m_controls);

	m_exitButton = new MenuButton(window, input, gameState, m_rt, sf::Vector2f(256, 128), sf::Vector2f(200, 800), "Exit Button", ButtonType::Exit,46, m_controls);

	/*if (!m_mmFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}

	m_mmText.setFont(m_mmFont); // font is a sf::Font

	// set the string to display
	m_mmText.setString("MainMenu");

	// set the character size
	m_mmText.setCharacterSize(48); // in pixels, not points!

	// set the color
	m_mmText.setFillColor(sf::Color::Red);

	m_mmText.setPosition(0, 0);*/
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


