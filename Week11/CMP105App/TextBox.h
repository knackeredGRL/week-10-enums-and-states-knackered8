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

    const bool& GetVisible()
    {
        return m_visible;
    }

    void SetVisible(bool vis)
    {
        m_visible = vis;
    }

private:
    //RectangleShape m_box;
    sf::Text m_txt;
    sf::Font m_font;
    bool m_visible = false;







};

