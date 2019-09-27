#include "DesignHandler.h"

void DesignHandler::Setup(sf::Vector2f startPos, sf::Vector2f controlSizeInGrids)
{
	if (!this->GetWindow())
		return;

	/*
	float gx[3];
	float gy[3];

	float igx[2];
	igx[0] = ceil(13.0f / 2.0f);
	igx[1] = 13;

	float igy[2];
	igy[0] = ceil(4.0f / 2.0f);
	igy[1] = 4;

	gx[0] = 0;
	gx[1] = 7;
	gx[2] = 13;

	gy[0] = 0;
	gy[1] = 2;
	gy[2] = 4;
	*/

	float centerX = ceil(controlSizeInGrids.x / 2.0f);
	float centerY = ceil(controlSizeInGrids.y / 2.0f);

	originalPosition[0] = sf::Vector2f(-7, -7);
	originalPosition[1] = sf::Vector2f(-7 + (centerX * 8), -7);
	originalPosition[2] = sf::Vector2f(-7 + (controlSizeInGrids.x * 8), -7);
	originalPosition[3] = sf::Vector2f(-7, -7 + (centerY * 8));
	originalPosition[4] = sf::Vector2f(-7 + (controlSizeInGrids.x * 8), -7 + (centerY * 8));
	originalPosition[5] = sf::Vector2f(-7, -7 + (controlSizeInGrids.y * 8));
	originalPosition[6] = sf::Vector2f(-7 + (centerX * 8), -7 + (controlSizeInGrids.y * 8));
	originalPosition[7] = sf::Vector2f(-7 + (controlSizeInGrids.x * 8), -7 + (controlSizeInGrids.y * 8));


	/*
	originalPosition[0] = sf::Vector2f(-7, -7);
	originalPosition[1] = sf::Vector2f(-7 + (7 * 8), -7);
	originalPosition[2] = sf::Vector2f(-7 + (13 * 8), -7);
	originalPosition[3] = sf::Vector2f(-7, -7 + (2 * 8));
	originalPosition[4] = sf::Vector2f(-7 + (13 * 8), -7 + (2 * 8));
	originalPosition[5] = sf::Vector2f(-7, -7 + (4 * 8));
	originalPosition[6] = sf::Vector2f(-7 + (7 * 8), -7 + (4 * 8));
	originalPosition[7] = sf::Vector2f(-7 + (13 * 8), -7 + (4 * 8));
	*/

	// top left
	box[0].setFillColor(sf::Color(10, 36, 106));
	box[0].setOutlineColor(sf::Color(255, 255, 255));
	box[0].setOutlineThickness(1);
	box[0].setPosition(sf::Vector2f(startPos.x + originalPosition[0].x, startPos.y + originalPosition[0].y));
	box[0].setSize(sf::Vector2f(5, 5));
	// top center
	box[1].setFillColor(sf::Color(10, 36, 106));
	box[1].setOutlineColor(sf::Color(255, 255, 255));
	box[1].setOutlineThickness(1);
	box[1].setPosition(sf::Vector2f(startPos.x + originalPosition[1].x, startPos.y + originalPosition[1].y));
	box[1].setSize(sf::Vector2f(5, 5));
	// top right
	box[2].setFillColor(sf::Color(10, 36, 106));
	box[2].setOutlineColor(sf::Color(255, 255, 255));
	box[2].setOutlineThickness(1);
	box[2].setPosition(sf::Vector2f(startPos.x + originalPosition[2].x, startPos.y + originalPosition[2].y));
	box[2].setSize(sf::Vector2f(5, 5));
	// middle left
	box[3].setFillColor(sf::Color(10, 36, 106));
	box[3].setOutlineColor(sf::Color(255, 255, 255));
	box[3].setOutlineThickness(1);
	box[3].setPosition(sf::Vector2f(startPos.x + originalPosition[3].x, startPos.y + originalPosition[3].y));
	box[3].setSize(sf::Vector2f(5, 5));
	// middle right
	box[4].setFillColor(sf::Color(10, 36, 106));
	box[4].setOutlineColor(sf::Color(255, 255, 255));
	box[4].setOutlineThickness(1);
	box[4].setPosition(sf::Vector2f(startPos.x + originalPosition[4].x, startPos.y + originalPosition[4].y));
	box[4].setSize(sf::Vector2f(5, 5));
	// bottom left
	box[5].setFillColor(sf::Color(10, 36, 106));
	box[5].setOutlineColor(sf::Color(255, 255, 255));
	box[5].setOutlineThickness(1);
	box[5].setPosition(sf::Vector2f(startPos.x + originalPosition[5].x, startPos.y + originalPosition[5].y));
	box[5].setSize(sf::Vector2f(5, 5));
	// bottom center
	box[6].setFillColor(sf::Color(10, 36, 106));
	box[6].setOutlineColor(sf::Color(255, 255, 255));
	box[6].setOutlineThickness(1);
	box[6].setPosition(sf::Vector2f(startPos.x + originalPosition[6].x, startPos.y + originalPosition[6].y));
	box[6].setSize(sf::Vector2f(5, 5));
	// bottom right
	box[7].setFillColor(sf::Color(10, 36, 106));
	box[7].setOutlineColor(sf::Color(255, 255, 255));
	box[7].setOutlineThickness(1);
	box[7].setPosition(sf::Vector2f(startPos.x + originalPosition[7].x, startPos.y + originalPosition[7].y));
	box[7].setSize(sf::Vector2f(5, 5));
}

void DesignHandler::Draw()
{
	if (!visible)
		return; // do not draw if invisible
	
	window->draw(box[0]);
	window->draw(box[1]);
	window->draw(box[2]);
	window->draw(box[3]);
	window->draw(box[4]);
	window->draw(box[5]);
	window->draw(box[6]);
	window->draw(box[7]);
}


void DesignHandler::SetPosition(sf::Vector2f position)
{
	//if (position.x > (this->GetWindow()->getPosition().x - originalPosition[1].x))
	//	return;

	UIBase::SetPosition(position);
	
	box[0].setPosition(position + originalPosition[0]);
	box[1].setPosition(position + originalPosition[1]);
	box[2].setPosition(position + originalPosition[2]);
	box[3].setPosition(position + originalPosition[3]);
	box[4].setPosition(position + originalPosition[4]);
	box[5].setPosition(position + originalPosition[5]);
	box[6].setPosition(position + originalPosition[6]);
	box[7].setPosition(position + originalPosition[7]);
}

void DesignHandler::SetSize(sf::Vector2f size)
{
	UIBase::SetSize(size);

	//box[0].setPosition(box[0].getPosition() + size);
}

