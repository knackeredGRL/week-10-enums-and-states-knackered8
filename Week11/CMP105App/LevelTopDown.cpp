#include "LevelTopDown.h"
#include "PlayerTopDown.h"
#include "NPC.h"
#include "TextBox.h"

LevelTopDown::LevelTopDown(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud, sf::RenderTexture* renderTexture)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;
	m_rt = renderTexture;

	m_player = new PlayerTopDown(in, m_rt);
	m_npc = new NPC(in, renderTexture,hwnd, sf::Vector2f(0,1), sf::Vector2f(500,200), sf::Vector2f(64, 64), "gfx/BalloonerSpriteSheet.png");
	//m_txtBox = new TextBox(in,renderTexture, sf::Vector2f(hwnd->getSize().x, 300), sf::Vector2f(hwnd->getSize().x/2,880 ), "gfx/BalloonerSpriteSheet.png");

}

LevelTopDown::~LevelTopDown()
{
}

void LevelTopDown::handleInput(float dt)
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

void LevelTopDown::update(float dt)
{

	m_player->handleInput(dt);
	m_player->update(dt);
	m_npc->update(dt, m_player->getCollisionBox());
	//m_txtBox->update(dt);
}

void LevelTopDown::render()
{
	beginDraw();
	//mm->render();

	
	m_rt->draw(*m_player);
	m_npc->render();
	//m_txtBox->render();
	/*m_rt->draw(*ball);
	m_rt->draw(m_timesStartedText);*/
	
	endDraw();
}

void LevelTopDown::renderPause()
{
}

void LevelTopDown::onBegin()
{
	m_player->setPosition(m_player->GetStartPosition());
	m_player->SetStepVelocity(sf::Vector2f(0, 0));
}

void LevelTopDown::onEnd()
{
}
