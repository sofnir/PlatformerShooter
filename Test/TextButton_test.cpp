#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include "../TextButton.h"

int main()
{
	sf::Mouse mouse;

	sf::Font font;
	font.loadFromFile("Data/font.ttf");

	TextButton button("NewButton", font, 20);
	button.setString("Button");
	button.setFont(font);
	button.setCharacterSize(40);
	button.setFillColor(sf::Color::Green);
	button.setHoverColor(sf::Color::Red);
	button.setResizing(true);
	button.setPosition(sf::Vector2f(200, 100));

	sf::RenderWindow window(sf::VideoMode(400, 300), "TextButton - test");
	
	while (window.isOpen())
	{
		sf::Vector2f mousePosition = sf::Vector2f(mouse.getPosition(window).x, mouse.getPosition(window).y);
		button.update(mousePosition);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && 
				event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
			{
				if (button.isHover(mousePosition))
				{
					std::cout << "It's work!\n";
				}
			}
		} 

		window.clear();		
		window.draw(button);
		window.display();
	} 
	return 0;
}