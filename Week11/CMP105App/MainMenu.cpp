#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture)
{
	window = rw;
	gameState = gs;
	input = in;
	m_rt = renderTexture;

	if (!m_mmFont.loadFromFile("font/arial.ttf"))
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

	m_mmText.setPosition(0, 0);
}

MainMenu::~MainMenu()
{
}

void MainMenu::handleInput(float dt)
{
}

void MainMenu::update(float dt)
{
	if (input->isPressed(sf::Keyboard::Space))
	{
		gameState->setCurrentState(State::LEVEL);
	}

}

void MainMenu::render()
{
	beginDraw();

	m_rt->draw(m_mmText);

	endDraw();

}
