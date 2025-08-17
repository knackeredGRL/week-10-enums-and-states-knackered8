#include "GameManager.h"
bool GameManager::s_isPaused = false;
int GameManager::s_lives = 3;
int GameManager::s_score = 0;

void GameManager::SetIsPaused(const bool& isPaused)
{
	s_isPaused = isPaused;

}

const bool& GameManager::GetIsPaused()
{
	return s_isPaused;
}

void GameManager::TakeDamage(const float& damage)
{
	s_lives = s_lives - damage;
}

int GameManager::GetLives()
{
	return s_lives;
}

void GameManager::IncreaseScore(const int& score)
{
	s_score += score;
}

const int& GameManager::GetScore()
{
	return s_score;
}

void GameManager::Death()
{
	if (s_lives <= 0)
	{
		GameManager::SetIsPaused(true);
	}
}