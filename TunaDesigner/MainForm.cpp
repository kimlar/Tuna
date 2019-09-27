#include "MainForm.h"

void MainForm::OnLoad()
{
}

void MainForm::OnMouseMove()
{
	if (moveButton4)
	{
		float mx = (float)sf::Mouse::getPosition().x - this->window.getPosition().x;
		float my = (float)sf::Mouse::getPosition().y - this->window.getPosition().y;
		float cx = mx - button4.GetSize().x / 2;
		float cy = my - button4.GetSize().y / 2;
		float dx = (float)((int)cx / 8) * 8 + 1;
		float dy = (float)((int)cy / 8) * 8 + 1 - 2 - 24;

		//
		// Check if button control is within the design form
		//
		if (mx < (formX + button4.GetSize().x / 2)) // Left side of form
			return;
		if (mx > (formX + formW - button4.GetSize().x/2 + 8)) // Right side of form
			return;
		if (my < (formY + button4.GetSize().y + 16)) // Top side of form
			return;
		if (my >(formY + formH + button4.GetSize().y)) // Bottom side of form
			return;

		// Change postion of our button control
		button4.SetPosition(sf::Vector2f(dx, dy));
		designHandler1.SetPosition(sf::Vector2f(dx, dy));
	}
}

void MainForm::OnMousePressed()
{
	designHandler1.SetVisible(false);
	designHandler2.SetVisible(true);
}

void MainForm::Button1_OnClick()
{
	ApplicationExit();
}

void MainForm::Button2_OnClick()
{
	//ApplicationExit();
}

void MainForm::Button3_OnClick()
{
	//ApplicationExit();
}

void MainForm::Button4_OnClick()
{
	//button1.SetPosition(sf::Vector2f(200, 100));
}

void MainForm::Button4_OnButtonPressed()
{
	moveButton4 = true;

	designHandler1.SetVisible(true);
	designHandler2.SetVisible(false);
}

void MainForm::Button4_OnButtonReleased()
{
	moveButton4 = false;
}
