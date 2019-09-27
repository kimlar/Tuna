#include "MainForm.h"

void MainForm::InitializeForm()
{
	//////////////////////////////////////////////////////////////////////////////////
	//
	/* Event - WaitEvent */
	//SetWaitEvent(true);
	//SetWaitTime(50);
	
	/* Form - Properties */
	SetTitle("This works");
	//SetStyle(sf::Style::Default);
	//SetPosition(sf::Vector2i(100, 100));
	SetSize(sf::Vector2i(800, 600));
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	button1.SetPosition(sf::Vector2f(100, 400));
	button1.SetSize(sf::Vector2f(100, 24));
	button1.SetText("Close");
	//button1.SetFontSize(16);
	button1.SetFontSize(12);
	button1.SetWindow(&window);
	button1.Setup();
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	button2.SetPosition(sf::Vector2f(210, 400));
	button2.SetSize(sf::Vector2f(100, 24));
	button2.SetText("Cancel");
	button2.SetFontSize(12);
	button2.SetWindow(&window);
	button2.Setup();
	//
	//////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////
	//
	label1.SetWindow(&window);
	label1.Setup();
	label1.SetText("This is a label");
	label1.SetPosition(sf::Vector2f(200, 200));
	//
	//////////////////////////////////////////////////////////////////////////////////
}


void MainForm::OnEvent(sf::Event &event)
{
	button1.CheckEvents(event);
	if (button1.buttonEvent == Button::ButtonEvent::OnClick)
		Button1_OnClick();

	button2.CheckEvents(event);
	if (button2.buttonEvent == Button::ButtonEvent::OnClick)
		Button2_OnClick();
}

void MainForm::OnDraw()
{
	button1.Draw();
	button2.Draw();
	label1.Draw();
}
