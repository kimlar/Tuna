#include "MainForm.h"

void MainForm::InitializeForm()
{
	//////////////////////////////////////////////////////////////////////////////////
	//
	/* Event - WaitEvent */
	SetWaitEvent(true);
	SetWaitTime(50);

	/* Form - Properties */
	SetTitle("Tuna Designer");
	//SetStyle(sf::Style::Default);
	//SetPosition(sf::Vector2i(100, 100));
	SetSize(sf::Vector2i(800, 600));	
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	button1.SetPosition(sf::Vector2f(10, 10));
	button1.SetSize(sf::Vector2f(100, 24));
	button1.SetText("Generate");
	//button1.SetFontSize(16);
	button1.SetFontSize(12);
	button1.SetWindow(&window);
	button1.Setup();
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	button2.SetPosition(sf::Vector2f(10, 100));
	button2.SetSize(sf::Vector2f(100, 24));
	button2.SetText("Add label");
	button2.SetFontSize(12);
	button2.SetWindow(&window);
	button2.Setup();
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	button3.SetPosition(sf::Vector2f(10, 130));
	button3.SetSize(sf::Vector2f(100, 24));
	button3.SetText("Add button");
	button3.SetFontSize(12);
	button3.SetWindow(&window);
	button3.Setup();
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	button4.SetPosition(sf::Vector2f(formX + 1 + (20 * 8), formY + 1 + (20 * 8)));
	button4.SetSize(sf::Vector2f(12 * 8, 3 * 8 - 1));
	button4.SetText("OK");
	button4.SetFontSize(12);
	button4.SetFrozen(true);
	button4.SetWindow(&window);
	button4.Setup();
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	label1.SetWindow(&window);
	label1.Setup();
	label1.SetText("This is a label");
	label1.SetPosition(sf::Vector2f(formX + (20 * 8), formY + (12 * 8)));
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	designHandler1.SetWindow(&window);
	designHandler1.Setup(sf::Vector2f(formX + 1 + (20 * 8), formY + 1 + (20 * 8)), sf::Vector2f(13,4));
	//designHandler1.SetPosition();
	designHandler1.SetSize(button2.GetSize());
	designHandler1.SetVisible(false);
	//
	//////////////////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////////////
	//
	designHandler2.SetWindow(&window);
	designHandler2.Setup(sf::Vector2f(formX, formY - 30 -1), sf::Vector2f(formW/8 + 1, formH/8 + 1 + ceil((float)30/8)));
	//designHandler2.Setup(sf::Vector2f(formX + 1 + (20 * 8), formY + 1 + (20 * 8)), sf::Vector2f(13, 4));
	//designHandler1.SetPosition();
	//designHandler2.SetSize(button2.GetSize());
	designHandler2.SetSize(sf::Vector2f(formW, formH));
	designHandler2.SetVisible(true);
	//
	//////////////////////////////////////////////////////////////////////////////////
}

void MainForm::OnEvent(sf::Event &event)
{
	// Check if designer form was clicked
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		float mx = (float)sf::Mouse::getPosition().x - this->window.getPosition().x;
		float my = (float)sf::Mouse::getPosition().y - this->window.getPosition().y;
		if (mx >= (formX + 8 - 1) && mx <= (formW + formX + 8) && my >= (formY) && my <= (formH + formY + 30 + 1))
		{
			OnMousePressed();
		}
	}

	button1.CheckEvents(event);
	if (button1.buttonEvent == Button::ButtonEvent::OnClick)
		Button1_OnClick();

	button2.CheckEvents(event);
	if (button2.buttonEvent == Button::ButtonEvent::OnClick)
		Button2_OnClick();

	button3.CheckEvents(event);
	if (button3.buttonEvent == Button::ButtonEvent::OnClick)
		Button3_OnClick();

	button4.CheckEvents(event);
	if (button4.buttonEvent == Button::ButtonEvent::OnClick)
		Button4_OnClick();
	if (button4.buttonEvent == Button::ButtonEvent::OnPressed)
		Button4_OnButtonPressed();
	if (button4.buttonEvent == Button::ButtonEvent::OnReleased)
		Button4_OnButtonReleased();
}

void MainForm::OnDraw()
{	
	sf::RectangleShape designerBackground;
	designerBackground.setFillColor(sf::Color(128,128,128));
	designerBackground.setPosition(sf::Vector2f(140, 100));
	designerBackground.setSize(sf::Vector2f(800-140-8, 600-100-8));
	window.draw(designerBackground);

	//float formX = 200;
	//float formY = 160 + 30; // title bar not included
	//float formW = 400;
	//float formH = 300;

	sf::RectangleShape designerFormBoarder;
	designerFormBoarder.setFillColor(sf::Color(0, 0, 0));
	designerFormBoarder.setPosition(sf::Vector2f(formX - 1, formY - 30 - 1));
	designerFormBoarder.setSize(sf::Vector2f(formW + 2, formH + 30 + 2));
	window.draw(designerFormBoarder);
	
	sf::RectangleShape designerFormTitle;
	designerFormTitle.setFillColor(sf::Color(10, 36, 106));
	designerFormTitle.setPosition(sf::Vector2f(formX, formY - 30));
	designerFormTitle.setSize(sf::Vector2f(formW, formH));
	window.draw(designerFormTitle);

	sf::RectangleShape designerFormBody;
	designerFormBody.setFillColor(sf::Color(212, 208, 200));
	designerFormBody.setPosition(sf::Vector2f(formX, formY));
	designerFormBody.setSize(sf::Vector2f(formW, formH));
	window.draw(designerFormBody);

	sf::RectangleShape gridDot;
	gridDot.setFillColor(sf::Color(0, 0, 0));	
	gridDot.setSize(sf::Vector2f(1, 1));

	for (float y = formY / 8; y < (formY + formH) / 8; y++)
	{
		for (float x = formX / 8; x < (formX + formW) / 8; x++)
		{
			gridDot.setPosition(sf::Vector2f(x * 8, y * 8));
			window.draw(gridDot);
		}
	}
	
	button1.Draw();
	button2.Draw();
	button3.Draw();
	button4.Draw();

	sf::RectangleShape label1_background;
	label1_background.setFillColor(sf::Color(212, 208, 200));
	//label1_background.setFillColor(sf::Color(100, 160, 160));
	label1_background.setPosition(label1.GetPosition());
	label1_background.setSize(sf::Vector2f((float)(int)(label1.GetSFText()->getLocalBounds().width / 8)*8 + 8 + 1, 2 * 8 + 1));
	window.draw(label1_background);

	label1.Draw();
	
	designHandler1.Draw();
	designHandler2.Draw();
}
