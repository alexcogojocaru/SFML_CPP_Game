#include "Animation.h"

/*
	0 = idle
	1 = walk
	2 = attack
	3 = death
	4 = jump
	5 = spin attack
	6 = dash
	7 = taunt
*/

Animation::Animation() 
	: totalTime(0.0f)
{
	Animation::initRowImages();

	currentImage.x = 0;
	
	shapeRect.width = animationWidth;
	shapeRect.height = animationHeight;
}

void Animation::Update(unsigned row, float deltaTime, bool right)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;

		currentImage.x++;

		if (currentImage.x >= rowImages.at(currentImage.y))
		{
			currentImage.x = 0;
		}
	}
	
	shapeRect.top = currentImage.y * animationTop;

	if (right)
	{
		shapeRect.left = currentImage.x * abs(shapeRect.width);
		shapeRect.width = abs(shapeRect.width);
	}
	else
	{
		shapeRect.left = (currentImage.x + 1) * abs(shapeRect.width);
		shapeRect.width = -abs(shapeRect.width);
	}
}

void Animation::initRowImages()
{
	rowImages.push_back(16);
	rowImages.push_back(8);
	rowImages.push_back(30);
	rowImages.push_back(40);
	rowImages.push_back(25);
	rowImages.push_back(30);
	rowImages.push_back(8);
	rowImages.push_back(18);
}