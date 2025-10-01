#pragma once
#include "Player.h"

class PlayerTopDown : public Player
{
public: 
	PlayerTopDown(Input* in, sf::RenderTexture* rt);
	~PlayerTopDown();
	void update(float dt);
	void handleInput(float dt);
	void render();


private:
	

};

