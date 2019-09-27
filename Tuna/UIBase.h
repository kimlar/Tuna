#pragma once

#include <SFML/Graphics.hpp>

class UIBase
{
/* Position */
public:
	void SetPosition(sf::Vector2f position);
	sf::Vector2f GetPosition();
private:
	sf::Vector2f position;

/* Size */
public:
	void SetSize(sf::Vector2f size);
	sf::Vector2f GetSize();
private:
	sf::Vector2f size;

/* Window */
public:
	void SetWindow(sf::RenderWindow* window);
	sf::RenderWindow* GetWindow();
protected:
	sf::RenderWindow* window;
private:
};
