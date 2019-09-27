#include "Button.h"

void Button::Setup()
{
	if (!this->GetWindow())
		return;

	SetPosition(GetPosition());
//	orignalPosition = GetPosition();

	label.SetWindow(this->GetWindow());
	label.Setup();
	//label.SetText("Hello World!");
	labelPosition = sf::Vector2f(GetPosition().x + GetTextAdjustPositionX(), GetPosition().y + 4);
//	label.SetPosition(sf::Vector2f(labelPosition.x, labelPosition.y));

	buttonShape.setFillColor(sf::Color(212, 208, 200));
	//buttonShape.setOutlineColor(sf::Color(70,70,70));
	//buttonShape.setOutlineThickness(1);
	//buttonShape.setPosition(GetPosition());
	buttonShape.setSize(GetSize());

}

void Button::Draw()
{
	window->draw(buttonShape);

	if (isDown)
		window->draw(lineDown, 12, sf::Lines);
	else
		window->draw(lineUp, 12, sf::Lines);

	label.Draw();
}

void Button::CheckEvents(sf::Event &event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		mx = (float)event.mouseMove.x;
		my = (float)event.mouseMove.y;

		float bx = GetPosition().x;
		float by = GetPosition().y;
		float bw = GetSize().x;
		float bh = GetSize().y;

		if (!(mx >= (bx - 1) && mx < (bx + bw + 1) && my >= (by - 1) && my < (by + bh + 1)))
		{
			isDown = false;
			buttonEvent = ButtonEvent::OnReleased;
		}
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		float bx = GetPosition().x;
		float by = GetPosition().y;
		float bw = GetSize().x;
		float bh = GetSize().y;

		if (mx >= (bx - 1) && mx < (bx + bw + 1) && my >= (by - 1) && my < (by + bh + 1))
		{
			if (!isFrozen)
				isDown = true;

			buttonEvent = ButtonEvent::OnPressed;
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		if (isDown)
			buttonEvent = ButtonEvent::OnClick;
		else
			buttonEvent = ButtonEvent::OnReleased;

		isDown = false;
	}

	if (isDown)
	{
		buttonShape.setPosition(orignalPosition.x + 1, orignalPosition.y + 1);
		label.GetSFText()->setPosition(sf::Vector2f(labelPosition.x + 1, labelPosition.y + 1));
	}
	else
	{
		buttonShape.setPosition(orignalPosition.x, orignalPosition.y);
		label.GetSFText()->setPosition(sf::Vector2f(labelPosition.x, labelPosition.y));
	}
}

void Button::SetPosition(sf::Vector2f position)
{
	UIBase::SetPosition(position);
	orignalPosition = position;
	labelPosition = sf::Vector2f(GetPosition().x + GetTextAdjustPositionX(), GetPosition().y + 4);

	label.GetSFText()->setPosition(sf::Vector2f(labelPosition.x, labelPosition.y));
	buttonShape.setPosition(GetPosition());

	lineDown[0] = sf::Vertex(sf::Vector2f(GetPosition().x - 1, GetPosition().y - 1), sf::Color(64, 64, 64));
	lineDown[1] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y - 1), sf::Color(64, 64, 64));
	lineDown[2] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y), sf::Color(64, 64, 64));
	lineDown[3] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y + GetSize().y + 1), sf::Color(64, 64, 64));
	lineDown[4] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y + GetSize().y), sf::Color(255, 255, 255));
	lineDown[5] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y + GetSize().y), sf::Color(255, 255, 255));
	lineDown[6] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y + GetSize().y + 1), sf::Color(255, 255, 255));
	lineDown[7] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y), sf::Color(255, 255, 255));
	lineDown[8] = sf::Vertex(sf::Vector2f(GetPosition().x + 1, GetPosition().y + 1), sf::Color(128, 128, 128));
	lineDown[9] = sf::Vertex(sf::Vector2f(GetPosition().x + 1, GetPosition().y + GetSize().y), sf::Color(128, 128, 128));
	lineDown[10] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x - 1, GetPosition().y), sf::Color(128, 128, 128));
	lineDown[11] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y), sf::Color(128, 128, 128));

	lineUp[0] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y - 1), sf::Color(255, 255, 255));
	lineUp[1] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y - 1), sf::Color(255, 255, 255));
	lineUp[2] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y - 1), sf::Color(255, 255, 255));
	lineUp[3] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y + GetSize().y), sf::Color(255, 255, 255));
	lineUp[4] = sf::Vertex(sf::Vector2f(GetPosition().x - 1, GetPosition().y + GetSize().y), sf::Color(64, 64, 64));
	lineUp[5] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y + GetSize().y), sf::Color(64, 64, 64));
	lineUp[6] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y + GetSize().y), sf::Color(64, 64, 64));
	lineUp[7] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x, GetPosition().y - 1), sf::Color(64, 64, 64));
	lineUp[8] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x - 1, GetPosition().y), sf::Color(128, 128, 128));
	lineUp[9] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x - 1, GetPosition().y + GetSize().y - 1), sf::Color(128, 128, 128));
	lineUp[10] = sf::Vertex(sf::Vector2f(GetPosition().x + GetSize().x - 1, GetPosition().y + GetSize().y - 1), sf::Color(128, 128, 128));
	lineUp[11] = sf::Vertex(sf::Vector2f(GetPosition().x, GetPosition().y + GetSize().y - 1), sf::Color(128, 128, 128));
}

void Button::SetText(std::string text)
{
	label.SetText(text);
	labelPosition = sf::Vector2f(GetPosition().x + GetTextAdjustPositionX(), GetPosition().y + 4);
}

void Button::SetFontSize(int px)
{
	label.GetSFText()->setCharacterSize(px);
}

float Button::GetTextWidth()
{
	return label.GetSFText()->getLocalBounds().width;
}

float Button::GetTextAdjustPositionX()
{
	return (float)((int)(GetSize().x / 2 - GetTextWidth() / 2));
}
