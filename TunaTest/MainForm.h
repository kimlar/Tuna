#pragma once

#include <SFML/Graphics.hpp>

#include "Form.h"
#include "Label.h"
#include "Button.h"

class MainForm : public Form
{
public:
	void OnLoad();
private:

//////////////////////////////////////////////////////////////////////////////////
//
private:
	void InitializeForm();
	void OnEvent(sf::Event &event);
	void OnDraw();

	void Button1_OnClick();
	Button button1;

	void Button2_OnClick();
	Button button2;

	Label label1;
//
//////////////////////////////////////////////////////////////////////////////////

};
