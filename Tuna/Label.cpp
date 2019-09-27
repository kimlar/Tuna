#include "Label.h"

/*
Label::Label(sf::RenderWindow &window)
{
	this->SetWindow(window);
}

Label::~Label()
{
}
*/

void Label::Setup()
{
	if (!this->GetWindow())
		return;

	//font.loadFromFile("Resources/Fonts/OpenSans-SemiBold.ttf");
	font.loadFromFile("Resources/Fonts/OpenSans-Regular.ttf");

	text.setFont(font);
	text.setCharacterSize(12);
	text.setPosition(GetPosition());
	//text.setString("Hello SFML");
	text.setFillColor(sf::Color(0, 0, 0));
}

void Label::Draw()
{
	//window.draw(text);
	//rw->draw(text);
	//GetWindow()->draw(text);
	window->draw(text);
}

void Label::SetPosition(sf::Vector2f position)
{
	UIBase::SetPosition(position);
	text.setPosition(position);
}

void Label::SetText(std::string text)
{
	this->text.setString(text);
}

std::string Label::GetText()
{
	return text.getString();
}
