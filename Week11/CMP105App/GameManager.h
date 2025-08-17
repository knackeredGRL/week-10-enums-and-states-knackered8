#pragma once
static class GameManager
{
public:

	//sets is paused to true pausing game
	static void SetIsPaused(const bool& isPaused);

	static const bool& GetIsPaused();
	//takes 1 away from static lives value
	static void TakeDamage(const float& damage);

	static int GetLives();
	//increases static score value by 1
	static void IncreaseScore(const int& score);
	static const int& GetScore();

	//if lives = 0 pauses game
	static void Death();

	static void SetScore(const int& score) { s_score = score; }

	static void SetLives(const int& lives) { s_lives = lives; }


private:

	static bool s_isPaused;
	static int s_lives;
	static int s_score;


};

