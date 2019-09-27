#pragma once

#include <SFML/Graphics.hpp>

#include "Form.h"
#include "Label.h"
#include "Button.h"
#include "DesignHandler.h"

//
// TODO LIST:
//
//  1. 
//  2.
//
//
//
//

//
// - Click on control to select it with design handler
// - Click outside to deselect it
// + Move around with the control & design handler
// - Resize Horizontally with design handler (middle left and middle right)
// - Resize Vertically with design handler (top center and bottom center)
// - Resize H+V with the design handler (those in the corners)
//

class MainForm : public Form
{
public:
	void OnLoad();
	void OnMouseMove();
	void OnMousePressed();

private:
	bool moveButton4;

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

	void Button3_OnClick();
	Button button3;

	void Button4_OnClick();
	void Button4_OnButtonPressed();
	void Button4_OnButtonReleased();
	Button button4;

	Label label1;

	//void DesignHandler1_OnClick();
	DesignHandler designHandler1; // for button4

	//void DesignHandler2_OnClick();
	DesignHandler designHandler2; // for design form

	//
	//////////////////////////////////////////////////////////////////////////////////

	// Special need for design form
	float formX = 200;
	float formY = 160 + 30; // title bar not included
	float formW = 50 * 8; //400;
	float formH = 40 * 8; //300;

};
