#include "UIBase.h"

void UIBase::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f UIBase::GetPosition()
{
	return position;
}

void UIBase::SetSize(sf::Vector2f size)
{
	this->size = size;
}

sf::Vector2f UIBase::GetSize()
{
	return size;
}

void UIBase::SetWindow(sf::RenderWindow* window)
{
	this->window = window;
}

sf::RenderWindow* UIBase::GetWindow()
{
	return window;
}
