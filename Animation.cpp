#include "Animation.h"

Animation::Animation(const sf::Vector2f & frameSize, sf::Vector2u imageCount, float switchTime)
{
	//set values
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	timer.restart();
	currentImage.x = 0;
	
	uvRect.width = frameSize.x;
	uvRect.height = frameSize.y;
}

void Animation::update(int row, bool faceRight)
{
	//set values
	currentImage.y = row;

	//when it is time for change animation frame 
	if (timer.getElapsedTime().asSeconds() >= switchTime)
	{
		//reset timer time and set next frame
		timer.restart();
		currentImage.x++;

		//when current frame is the last start over again 
		if (currentImage.x >= imageCount.x)
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
