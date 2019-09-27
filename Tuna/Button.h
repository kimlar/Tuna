#pragma once

#include <SFML/Graphics.hpp>

#include "UIBase.h"
#include "Label.h"

class Button : public UIBase
{
public:
	enum class ButtonEvent { None = 0, OnClick, OnPressed, OnReleased };
	ButtonEvent buttonEvent = ButtonEvent::None;

	void Setup();
	void Draw();

	void CheckEvents(sf::Event &event);

	void SetPosition(sf::Vector2f position);
	void SetText(std::string text);
	void SetFontSize(int px);

	void SetFrozen(bool frozen) { this->isFrozen = frozen; };

private:
	sf::Vector2f orignalPosition;

	Label label;
	sf::Vector2f labelPosition;

	sf::RectangleShape buttonShape;

	bool isDown;
	
	sf::Vertex lineDown[12];
	sf::Vertex lineUp[12];

	float mx;
	float my;

	float GetTextWidth();
	float GetTextAdjustPositionX();

	bool isFrozen;
};
