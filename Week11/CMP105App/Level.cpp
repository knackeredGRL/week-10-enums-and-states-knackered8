#include "Level.h"
#include "Player.h"
#include "ShootPointer.h"
#include "BulletManager.h"
#include "CollisionManager.h"


Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud, sf::RenderTexture* renderTexture)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;
	m_rt = renderTexture;


	//gameState = new GameState();
	//mm = new MainMenu(window);
	ball = new GameObject();


	//gameState->setCurrentState(State::MENU);

	m_texture = new sf::Texture();

	if (!m_texture->loadFromFile("gfx/Beach_Ball.png"))
	{
		// error...
	}

	ball->setTexture(m_texture);
	ball->setSize(sf::Vector2f(100, 100));
	ball->setOrigin(sf::Vector2f(50, 50));
	ball->setPosition(m_startingPos);

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	m_velocity = m_startingVelocity;

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
	m_timesStartedText.setString(std::to_string(m_timesStarted));

	// set the character size
	m_timesStartedText.setCharacterSize(24); // in pixels, not points!

	// set the color
	m_timesStartedText.setFillColor(sf::Color::Green);

	m_timesStartedText.setPosition(sf::Vector2f(200, 300));

	m_player = new Player(in,m_rt);

	m_shootPointer = new ShootPointer(in, m_rt, m_player);

	m_bulletManager = new BulletManager(in, m_rt, m_shootPointer);


	m_enemy = new Enemy(in, m_rt,sf::Vector2f(0,0), sf::Vector2f(500, 500), m_texture);

	m_colManager = new CollisionManager();
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

	m_shootPointer->handleInput(dt);
	m_bulletManager->handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	m_timesStartedText.setString(std::to_string(m_timesStarted));

	ball->move(m_velocity * 100.f * dt);

	if (ball->getPosition().x >= 1920)
		m_velocity.x = -m_velocity.x;
	else if (ball->getPosition().x <= 0)
		m_velocity.x = -m_velocity.x;
	else if (ball->getPosition().y >= 1080)
		m_velocity.y = -m_velocity.y;
	else if (ball->getPosition().y <= 0)
		m_velocity.y = -m_velocity.y;

	m_player->handleInput(dt);
	m_player->update(dt);
	m_shootPointer->update(dt);
	
	m_bulletManager->update(dt);

	m_enemy->update(dt);




	m_colManager->BulletEnemyCollision(m_bulletManager, m_enemy);
}

// Render level
void Level::render()
{
	beginDraw();
	//mm->render();



	m_rt->draw(*m_player);
	m_rt->draw(*ball);
	m_rt->draw(m_timesStartedText);
	m_rt->draw(*m_shootPointer);
	m_rt->draw(*m_enemy);
	m_bulletManager->RenderBullets();
	m_shootPointer->render();
	if (gameState->getCurrentState() == State::PAUSE)
	{
		renderPause();
	}


	endDraw();
}

void Level::renderPause()
{


	m_rt->draw(m_pauseText);

}

void Level::onBegin()
{
	m_timesStarted += 1;
	ball->setPosition(m_startingPos);
	m_player->setPosition(m_player->GetStartPosition());
	m_player->SetStepVelocity(sf::Vector2f(0, 0));
	m_bulletManager->ResetAllBullets();
	m_bulletManager->SetCanShoot(true);
	m_velocity = m_startingVelocity;


}

void Level::onEnd()
{



}


