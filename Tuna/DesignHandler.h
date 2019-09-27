#pragma once

#include <SFML/Graphics.hpp>

#include "UIBase.h"

class DesignHandler : public UIBase
{
public:
	void Setup(sf::Vector2f startPos, sf::Vector2f controlSizeInGrids);
	void Draw();

	void SetPosition(sf::Vector2f position);
	void SetSize(sf::Vector2f size);

	void SetVisible(bool visible) { this->visible = visible; };
	//bool GetVisible() { return visible; };

private:
	sf::RectangleShape box[8];
	sf::Vector2f originalPosition[8];

	bool visible = true;
};
