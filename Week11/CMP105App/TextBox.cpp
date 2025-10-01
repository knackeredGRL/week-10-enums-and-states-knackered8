#include "TextBox.h"

TextBox::TextBox(Input* in, sf::RenderTexture* rt, sf::Vector2f size, sf::Vector2f position, std::string textureString)
{
	if (!m_font.loadFromFile("font/editundo.ttf"))
	{
		std::cout << "font not loaded" << std::endl;
	}

	setRenderTexture(rt);

	m_txt.setFont(m_font); // font is a sf::Font

	// set the string to display
	m_txt.setString(" ");

	// set the character size
	m_txt.setCharacterSize(32); // in pixels, not points!

	// set the color
	m_txt.setFillColor(sf::Color::White);



	setSize(size);
	setOrigin(size / 2.f);


	setPosition(position);

	setFillColor(sf::Color::Black);

	m_txt.setPosition((position - size / 2.f) + sf::Vector2f(10, 35));


}

void TextBox::update(float dt)
{
	std::string line;
	std::ifstream myfile("example.txt");
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			m_txt.setString(line);
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";
}

void TextBox::render()
{
	m_rt->draw(*this);
	m_rt->draw(m_txt);
}
