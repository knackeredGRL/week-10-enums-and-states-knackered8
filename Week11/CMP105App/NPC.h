#pragma once
#include "Framework/GameObject.h"
class NPC :
    public GameObject
{
public:
    NPC(Input* in, sf::RenderTexture* rt, sf::Vector2f direction, sf::Vector2f position, std::string texture);
    NPC();
    ~NPC();

    void update(float dt);

    void handleInput(float dt);

    void render();

private:







};

