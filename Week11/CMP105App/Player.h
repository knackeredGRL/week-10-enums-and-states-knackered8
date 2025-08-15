#pragma once
#include "Framework/GameObject.h"

class Player :public GameObject
{
public:
	Player(Input* in, sf::RenderTexture* rt);
	~Player();
	void update(float dt );
	void handleInput(float dt);
	void render();
	void Setup();


private:
	float speed = 10;
	float acceleration = 2.f;

};

