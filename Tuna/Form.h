#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Form
{
public:
	void Run();
	virtual void InitializeForm() {};		// Form code automated by form designer

	virtual void OnCreate() {};				// Code that needs to be runned BEFORE the window/form is created
	virtual void OnDestroy() {};			// Code that needs to be runned AFTER the window/form is destroyed

	virtual void OnLoad() {};				// Code that needs to be runned AFTER the window/form is created (but before entering event loop)
	virtual void OnUnload() {};				// Code that needs to be runned BEFORE the window/form is destroyed

	virtual void OnEvent(sf::Event &event) {}; // Code that needs to be runned WHEN as certain event occurs
	virtual void OnMouseMove() {};

	virtual void OnUpdate(float dt) {};	// Code that needs to be runned WHEN the window/form is being updated (with delta time in seconds)
	virtual void OnDraw() {};				// Code that needs to be runned WHEN the window/form is being redrawned

/* Application */
public:
	void ApplicationExit() { run = false; };
private:
	bool run = true;

/* Window */
public:
protected:
	sf::RenderWindow window;
private:
	void ProcessEvent(sf::Event &event);

/* Window - Title */
public:
	std::string GetTitle();
	void SetTitle(std::string title);
private:
	std::string title = "My Application";

/* Window - Size */
public:
	sf::Vector2i GetSize();
	void SetSize(sf::Vector2i size);
private:
	sf::Vector2i size = sf::Vector2i(800, 600);

/* Window - Position */
public:
	sf::Vector2i GetPosition();
	void SetPosition(sf::Vector2i position);
private:
	sf::Vector2i position = sf::Vector2i(-1, -1);

/* Window - Style */
public:
	int GetStyle();
	void SetStyle(int style);
private:
	int style = sf::Style::Default;

/* Event - WaitEvent */
public:
	void SetWaitEvent(bool waitEvent) { this->waitEvent = waitEvent; };
	bool GetWaitEvent() { return waitEvent; };
	void SetWaitTime(int waitTime) { this->waitTime = waitTime; };
	int GetWaitTime() { return waitTime; };
private:
	bool waitEvent = true;
	int waitTime = 50; // wait in ms

/* Mouse */
public:
	sf::Vector2f GetMousePosition();
private:
	sf::Vector2f mousePosition;
	bool mouseLeftIsPressed;
};
