#pragma once
#include "FrameWork/GameObject.h"
#include <iostream>
#include <fstream>
class TextBox :
    public GameObject
{
public:

    TextBox(Input* in, sf::RenderTexture* rt, sf::Vector2f size, sf::Vector2f position, std::string textureString);

    void update(float dt);

    void render();

private:
    //RectangleShape m_box;
    sf::Text m_txt;
    sf::Font m_font;








};

