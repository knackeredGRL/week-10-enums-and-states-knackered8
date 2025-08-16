#include "Controls.h"

Controls::Controls(sf::RenderWindow* rw, Input* in, GameState* gs, sf::RenderTexture* renderTexture, sf::Vector2f size, sf::Vector2f position)
{
	window = rw;
	gameState = gs;
	input = in;
	m_rt = renderTexture;
	
	m_alive = false;
	


	if (!m_mmFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}

	m_mmText.setFont(m_mmFont); // font is a sf::Font

	// set the string to display
	m_mmText.setString("Dont fall offscreen, Use W to jump, Use A(Left),\n D(Right) and aim bullets with mouse and left click to fire, \navoid touching balloons with player, shoot balloons with bullets for points");

	// set the character size
	m_mmText.setCharacterSize(20); // in pixels, not points!

	// set the color
	m_mmText.setFillColor(sf::Color::White);



	setSize(size);
	setOrigin(size / 2.f);


	setPosition(position);

	setFillColor(sf::Color::Black);

	m_mmText.setPosition((position - size / 2.f) + sf::Vector2f(0, 25));

}

Controls::Controls()
{
}

Controls::~Controls()
{
}

void Controls::update(float dt)
{
}

void Controls::handleInput(float dt)
{
}

void Controls::render()
{
	//beginDraw();

	if (m_alive)
	{
		m_rt->draw(*this);
		m_rt->draw(m_mmText);
	}
	

	//endDraw();

}