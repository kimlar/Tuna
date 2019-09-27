#include "MainForm.h"

void MainForm::OnLoad()
{
}

void MainForm::Button1_OnClick()
{
	ApplicationExit();
}

void MainForm::Button2_OnClick()
{
	button1.SetPosition(sf::Vector2f(200, 100));
}
