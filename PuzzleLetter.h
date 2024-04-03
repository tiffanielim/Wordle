//
// Created by Tiffanie Lim on 12/12/23.
//

#include <SFML/Graphics.hpp>

class PuzzleLetter
{
public:
	//defines the state used for solutions
	enum SolutionState { NO_STATE, CORRECT, WRONG_POS };

	PuzzleLetter(const sf::IntRect& bounds, const sf::Font& font);
	virtual ~PuzzleLetter() = default;

	//draws the button
	void draw(sf::RenderWindow& renderWindow) const;

	//gets the letter associated with the object
	char getLetter() const;

	//sets the letter to the specified letter
	void setLetter(const char letter);

	//changes the background colour and stores the solution state
	void setSolutionState(const SolutionState& solutionState);

	//get solution state of this element
	SolutionState getSolutionState() const;

private:
	//the bounds of the rectangle used for isPositionInside().
	sf::IntRect _bounds;

	//the character shown on the puzzle letter.
	char _letter;

	//element background
	sf::RectangleShape _background;

	//text render
	sf::Text _textVisual;

	//the current solution state of this letter
	SolutionState _currentState;

	//changes the background colour to the specified colour
	void setBackgroundColour(const sf::Color& colour);
};