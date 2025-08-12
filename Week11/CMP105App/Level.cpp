#include "Level.h"
//#include "MainMenu.h"

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
	ball->setPosition(sf::Vector2f(100, 100));

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	velocity = sf::Vector2f(1, -1);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	

	ball->move(velocity * 100.f * dt);

	if (ball->getPosition().x >= 1200)
		velocity.x = -velocity.x;
	else if (ball->getPosition().x <= 0)
		velocity.x = -velocity.x;
	else if (ball->getPosition().y >= 675)
		velocity.y = -velocity.y;
	else if (ball->getPosition().y <= 0)
		velocity.y = -velocity.y;


	if (input->isPressed(sf::Keyboard::Space))
	{
		gameState->setCurrentState(State::MENU);
	}


}

// Render level
void Level::render()
{
	beginDraw();
	//mm->render();


	window->draw(*ball);
	endDraw();
}

