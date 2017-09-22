#pragma once
#include <SFML\Graphics.hpp>

class Animation
{
public:
	Animation(const sf::Vector2f & frameSize, sf::Vector2u imageCount, float switchTime);	

	sf::IntRect getuvRect() const { return uvRect; }
	void update(int row, bool faceRight); /*change frames (make animation),
														   row - current animation for example idle / jumping,
														   deltaTime - time between previous and current game loop,
														   faceRight - current face direction*/
private:
	sf::Vector2u imageCount; //rows and columns in the texture tile
	sf::Vector2u currentImage; //current index of the frame to display from the texture tile 

	sf::Clock timer;
	float switchTime; //time between single frames 

	sf::IntRect uvRect; //IntRect - single frame index and size to display
};