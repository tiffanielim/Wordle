//
// Created by Tiffanie Lim on 12/7/23.
//
#pragma once

#include <SFML/Graphics.hpp>
class Button
{
public:
	Button(const sf::IntRect& bounds, const std::string& text, const int actionID, const sf::Font& font);
	virtual ~Button() = default;

	void draw(sf::RenderWindow& renderWindow) const;

	//gets the actionID associated with the button that can be used for determining what should be done when it's pressed
	int getActionID() const;

	//updates the hovering state to the specified value
	void setHovering(const bool isHovering);

	//returns true if the position is inside this button's bounds
	bool isPositionInside(const sf::Vector2i& mousePosition) const;

	//changes the background colour to the specified colour
	void setBackgroundColour(const sf::Color& colour);

	//uses preset colours to change the background colour only if the specified colourID is greater than the current value
	void applyColourID(const int colourID);

private:
	//the bounds of the rectangle used for isPositionInside()
	sf::IntRect _bounds;

	//a number that can be used to give context for when the button is detected to have been clicked
	int _actionID;

	//true when the mouse is over the rectangle causing a colour change
	bool _isHovered;

	//text to centre in the button
	std::string _text;

	//button background
	sf::RectangleShape _background;

	sf::Text _textVisual;

	//the current colour ID set via applyColourID
	int _colourID;
};

