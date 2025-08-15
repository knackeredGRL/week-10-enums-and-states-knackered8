#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;


	//gameState = new GameState();
	//mm = new MainMenu(window);
	ball = new GameObject();


	//gameState->setCurrentState(State::MENU);

	texture = new sf::Texture();

	if (!texture->loadFromFile("gfx/Beach_Ball.png"))
	{
		// error...
	}

	ball->setTexture(texture);
	ball->setSize(sf::Vector2f(100, 100));
	ball->setOrigin(sf::Vector2f(50, 50));
	ball->setPosition(m_startingPos);

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	velocity = m_startingVelocity;

	if (!m_pauseFont.loadFromFile("font/arial.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}

	m_pauseText.setFont(m_pauseFont); // font is a sf::Font

	// set the string to display
	m_pauseText.setString("PAUSED");

	// set the character size
	m_pauseText.setCharacterSize(96); // in pixels, not points!

	// set the color
	m_pauseText.setFillColor(sf::Color::Red);

	m_pauseText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);


	m_timesStartedText.setFont(m_pauseFont); // font is a sf::Font

	// set the string to display
	m_timesStartedText.setString(std::to_string(timesStarted));

	// set the character size
	m_timesStartedText.setCharacterSize(24); // in pixels, not points!

	// set the color
	m_timesStartedText.setFillColor(sf::Color::Green);

	m_timesStartedText.setPosition(sf::Vector2f(200, 300));




}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Space))
	{
		onBegin();
		gameState->setCurrentState(State::MENU);
		onEnd();
	}

	switch (gameState->getCurrentState())
	{
	case(State::LEVEL):
	{
		if (input->isPressed(sf::Keyboard::P))
		{
			gameState->setCurrentState(State::PAUSE);
		}
		break;
	}
	case(State::PAUSE):
	{
		if (input->isPressed(sf::Keyboard::P))
		{

			gameState->setCurrentState(State::LEVEL);
		}
		break;
	}

	}
}

// Update game objects
void Level::update(float dt)
{
	m_timesStartedText.setString(std::to_string(timesStarted));

	ball->move(velocity * 100.f * dt);

	if (ball->getPosition().x >= 1200)
		velocity.x = -velocity.x;
	else if (ball->getPosition().x <= 0)
		velocity.x = -velocity.x;
	else if (ball->getPosition().y >= 675)
		velocity.y = -velocity.y;
	else if (ball->getPosition().y <= 0)
		velocity.y = -velocity.y;


}

// Render level
void Level::render()
{
	beginDraw();
	//mm->render();




	window->draw(*ball);
	window->draw(m_timesStartedText);

	if (gameState->getCurrentState() == State::PAUSE)
	{
		renderPause();
	}


	endDraw();
}

void Level::renderPause()
{


	window->draw(m_pauseText);

}

void Level::onBegin()
{
	timesStarted += 1;
	ball->setPosition(m_startingPos);
	velocity = m_startingVelocity;


}

void Level::onEnd()
{



}


