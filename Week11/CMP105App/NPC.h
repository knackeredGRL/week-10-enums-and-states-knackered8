#pragma once
#include "Framework/GameObject.h"
class TextBox;
class PlayerTopDown;

class NPC :
    public GameObject
{
public:
    NPC(Input* in, sf::RenderTexture* rt,sf::RenderWindow* hwnd, sf::Vector2f direction, sf::Vector2f position, sf::Vector2f size, std::string texture);
    NPC();
    ~NPC();

    void update(float dt, const sf::FloatRect& otherCol);

    void handleInput(float dt);

    void render();

    void Collision(const sf::FloatRect& otherCollider);

private:
    std::unique_ptr<TextBox> m_txtBox;
   





};

