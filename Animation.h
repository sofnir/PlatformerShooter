#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Animation
{
public:
	Animation(const sf::Vector2f & frameSize, float switchTime);	

	sf::IntRect getuvRect() const { return uvRect; }
	void update(bool faceRight); //change frames (make animation)
	void createAnimation(const std::string & name, int row, int frames);
	void setCurrentAnimation(const std::string & name);

private:		
	struct AnimationValues
	{
		int row;
		int totalFrames;
	};

	std::map<std::string, AnimationValues> animations; //animation total frames and row in the texture
	std::string curretnAnimation;
	sf::Vector2u currentImage; //current index of the frame to display from the texture tile 

	sf::Clock timer;
	float switchTime; //time between single frames 
	sf::IntRect uvRect; //IntRect - single frame index and size to display
};