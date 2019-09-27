#pragma once

#include <SFML/Graphics.hpp>

#include "UIBase.h"

class Label : public UIBase
{
public:
	//Label(sf::RenderWindow &window);
	//virtual ~Label();

	void Setup();
	void Draw();

	//void SetText(std::string text);

	sf::Text* GetSFText() { return &text; };
	void SetPosition(sf::Vector2f position);

private:
	sf::Font font;
	//sf::Text text;

/* Text */
public:
	void SetText(std::string text);
	std::string GetText();
private:
	sf::Text text;
};
