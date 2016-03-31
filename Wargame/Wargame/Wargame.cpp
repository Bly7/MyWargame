// Wargame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	sf::Clock clock;
	Unit u;
	u.SetPosition(sf::Vector2f(200, 200));
	u.SetSpeed(100);

	sf::RectangleShape c(sf::Vector2f(10,10));
	c.setFillColor(sf::Color::Green);
	c.setPosition(u.GetPosition());

	// run the program as long as the window is open
	while (window.isOpen())
	{
		sf::Time dt = clock.restart();

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			u.GoToPosition(Vec2iTof(sf::Mouse::getPosition(window)));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			u.ClearMissions();
		}

		u.Update(dt.asSeconds());

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		c.setPosition(u.GetPosition());
		window.draw(c);

		// end the current frame
		window.display();
	}

	return 0;
}

