#include "UIManager.h"

UIManager::UIManager()
{
	m_uiFont = std::make_shared<sf::Font>();
	if (!m_uiFont->loadFromFile("font/arial.ttf"))
	{
		std::cout << "error texture not loaded" << std::endl;
	}



	/*m_uiLivesNum.setFont(*m_uiFont);

	m_uiLivesNum.setCharacterSize(100);
	m_uiLivesNum.setOrigin(50, 50);
	m_uiLivesNum.setString(std::to_string(3));
	m_uiLivesNum.setPosition(1500, 500);

	m_uiLivesText.setFont(*m_uiFont);

	m_uiLivesText.setCharacterSize(100);
	m_uiLivesText.setOrigin(50, 50);
	m_uiLivesText.setString("Lives: ");
	m_uiLivesText.setPosition(1500, 400);

	m_uiScoreText.setFont(*m_uiFont);

	m_uiScoreText.setCharacterSize(100);
	m_uiScoreText.setOrigin(50, 50);
	m_uiScoreText.setString("Score: ");
	m_uiScoreText.setPosition(1500, 100);

	m_uiScoreNum.setFont(*m_uiFont);

	m_uiScoreNum.setCharacterSize(100);
	m_uiScoreNum.setOrigin(50, 50);
	m_uiScoreNum.setString(std::to_string(0));
	m_uiScoreNum.setPosition(1500, 200);*/

	m_ui.setFont(*m_uiFont);

	m_ui.setCharacterSize(100);
	m_ui.setOrigin(50, 50);
	/*m_ui.setString(std::to_string(3));
	m_ui.setPosition(1500, 500);


	m_ui.setString("Lives: ");
	m_ui.setPosition(1500, 400);


	m_ui.setString("Score: ");
	m_ui.setPosition(1500, 100);


	m_ui.setString(std::to_string(0));
	m_ui.setPosition(1500, 200);*/

}
void UIManager::Update()
{
	//m_uiLivesNum.setString(std::to_string(GameManager::GetLives()));
	//m_uiScoreNum.setString(std::to_string(GameManager::GetScore()));
}
void UIManager::Render(sf::RenderTarget* rT)
{
	m_ui.setString(std::to_string(GameManager::GetLives()));
	m_ui.setPosition(1500, 500);

	//rT->draw(m_uiLivesNum);
	rT->draw(m_ui);

	m_ui.setString("Lives: ");
	m_ui.setPosition(1500, 400);

	rT->draw(m_ui);

	m_ui.setString("Score: ");
	m_ui.setPosition(1500, 100);

	rT->draw(m_ui);

	m_ui.setString(std::to_string(GameManager::GetScore()));
	m_ui.setPosition(1500, 200);

	rT->draw(m_ui);
	//rT->draw(m_uiLivesText);

	//rT->draw(m_uiScoreText);
	//rT->draw(m_uiScoreNum);
}