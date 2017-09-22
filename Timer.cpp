#include "Timer.h"

Timer::Timer()
{
	createText();
}

void Timer::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text);
}

void Timer::update(float dt)
{
	if (currentTime > 0)
	{
		switchTime -= dt;

		if (switchTime <= 0)
		{
			currentTime--;
			text.setString(std::to_string(currentTime));
			text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
			switchTime = 1.0f;
		}
	}
}

int Timer::getCurrentTime() const
{
	return currentTime;
}

void Timer::createText()
{
	text.setString("3");
	text.setFillColor(Color::Orange);
	text.setCharacterSize(45);
	text.setFont(Data::font);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(sf::Vector2f(Config::windowSize.x / 2.0f, Config::windowSize.y / 2.0f));
}
