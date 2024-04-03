//
// Created by Tiffanie Lim on 12/9/23.
//

#pragma once

#include <SFML/Graphics.hpp>

class HistogramBar
{
public:
	//initialises the histogram bar with text and size
	HistogramBar(const sf::IntRect& bounds, const sf::Font& font, const int title, const int value, const int max);
	virtual ~HistogramBar() = default;

	//draws the bar
	void draw(sf::RenderWindow & renderWindow) const;

	//changes the bar colour to the specified colour
	void setBarColour(const sf::Color& colour);

private:
	//the title text on the left
	std::unique_ptr<sf::Text> _titleText;

	//the bar visual
	std::unique_ptr<sf::RectangleShape> _bar;

	//the value of the element
	std::unique_ptr<sf::Text> _valueText;
};

