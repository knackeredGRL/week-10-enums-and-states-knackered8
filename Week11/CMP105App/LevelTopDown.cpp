#include "LevelTopDown.h"
#include "PlayerTopDown.h"

LevelTopDown::LevelTopDown(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud, sf::RenderTexture* renderTexture)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;
	m_rt = renderTexture;

	m_player = new PlayerTopDown(in, m_rt);


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
}

void LevelTopDown::render()
{
	beginDraw();
	//mm->render();

	
	m_rt->draw(*m_player);
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
