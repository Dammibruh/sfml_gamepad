# android in-game GAMEPAD for SFML

example:
```cpp
#include "gamepad.cpp"
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().height, sf::VideoMode::getDesktopMode().width), "main");
	sf::RectangleShape rect(sf::Vector2f(50.f, 50.f));
	rect.setPosition(200, 400);
	GamePad gp(window);
	gp.setPos(sf::Vector2f(1000.f, 250.f));
	while (window.isOpen())
	{
		auto rect_x = rect.getPosition().x, rect_y = rect.getPosition().y;
		gp.adjust();
		sf::Event event;
		if (gp.topTouch())
		{
			rect.setPosition(rect_x, rect_y - 10);
		}
		else if (gp.botTouch())
		{
			rect.setPosition(rect_x, rect_y + 10);
		}
		else if (gp.rightTouch())
		{
			rect.setPosition(rect_x + 10, rect_y);
		}
		else if (gp.leftTouch())
		{
			rect.setPosition(rect_x - 10, rect_y);
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		for (const auto &i : gp.getbtns())
		{
			window.draw(i);
		}
		window.draw(rect);
		window.display();
	}
}
```
