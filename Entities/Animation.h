#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

constexpr float switchTime = 0.1f;
constexpr int animationWidth = 170;
constexpr int animationTop = 96;
constexpr int animationHeight = 76;

class Animation
{
private:
	float totalTime;
	sf::Vector2u currentImage;
	vector<unsigned> rowImages;

public:
	sf::IntRect shapeRect;

public:
	Animation();

	void Update(unsigned row, float deltaTime, bool right);

	void initRowImages();
};
