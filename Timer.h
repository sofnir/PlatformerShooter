#pragma once
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include "Data.h"

class Timer : public sf::Drawable
{
public:
	Timer();
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void update(float dt);
	int getCurrentTime() const;

private:
	sf::Text text;

	void createText();
	float switchTime = 1.0f;
	int currentTime = 3;
};