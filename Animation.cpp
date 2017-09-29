#include "Animation.h"

Animation::Animation(const sf::Vector2f & frameSize, float switchTime)
{
	animations["Basic"] = { 0, 1 };
	curretnAnimation = "Basic";

	//set values
	this->switchTime = switchTime;
	timer.restart();
	currentImage.x = 0;
	
	uvRect.width = frameSize.x;
	uvRect.height = frameSize.y;
}

void Animation::update(bool faceRight)
{
	//set values
	currentImage.y = animations[curretnAnimation].row;

	//when it is time for change animation frame 
	if (timer.getElapsedTime().asSeconds() >= switchTime)
	{
		//reset timer time and set next frame
		timer.restart();
		currentImage.x++;

		//when current frame is the last start over again 
		if (currentImage.x >= animations[curretnAnimation].totalFrames)
		{
			currentImage.x = 0;
		}			
	}

	//set frame to displays 
	uvRect.top = currentImage.y * uvRect.height;

	//set correct frame flip dependence of the player face direction 
	if (faceRight)
	{
		//set right frame direction
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		//set left frame direction
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

void Animation::createAnimation(const std::string & name, int row, int frames)
{
	animations[name] = {row, frames};
}

void Animation::setCurrentAnimation(const std::string & name)
{
	if (curretnAnimation != name)
	{
		curretnAnimation = name;
	}	
}
