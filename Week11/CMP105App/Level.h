#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include <string>
#include <iostream>

#include "Enemy.h"

class Player;
class ShootPointer;
class BulletManager;



class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud, sf::RenderTexture* renderTexture );
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();
	void renderPause();
	void onBegin();
	void onEnd();


private:
	// Default variables for level class.
	//MainMenu* mm;
	GameObject* ball;
	sf::Texture* m_texture;
	sf::Vector2f m_velocity;
	sf::Text m_pauseText;
	sf::Text m_timesStartedText;
	sf::Font m_pauseFont;
	const sf::Vector2f m_startingPos = sf::Vector2f(100, 100);
	const sf::Vector2f m_startingVelocity = sf::Vector2f(1, -1);
	int m_timesStarted = 0;
	Player* m_player;

	ShootPointer* m_shootPointer;
	BulletManager* m_bulletManager;
	Enemy* m_enemy;
	

};