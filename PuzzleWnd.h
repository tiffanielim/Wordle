//
// Created by Tiffanie Lim on 12/12/23.
//

#pragma once
#include "WndInterface.h"
#include "KeyboardWnd.h"
#include "GuessGrid.h"

class PuzzleWnd :
	public WndInterface
{
public:
	//initialises the Puzzle with a new puzzle to be played.
	PuzzleWnd(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution);
	virtual ~PuzzleWnd();

	//updates the current state of the window.
	virtual void update(const float deltaTime) override;

	//draws all the components of the PuzzleWnd.
	virtual void draw(sf::RenderWindow & renderWindow) const override;

	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	virtual void handleKeyInput(const sf::Keyboard::Key key) override;

	const GuessGrid& getGuessGrid() const;

	//gets the state to check if the window is requesting an action.
	WndResultState getResultState() const override;

private:
	//reference to the font used for elements on the window.
	const sf::Font& _font;

	//title text
	sf::Text _gameTitle;

	//author text
	sf::Text _author;

	//the keyboard used for clicking for input
	KeyboardWnd _keyboard;

	//the grid of guesses where the keyboards input goes.
	GuessGrid _guessGrid;

	//the current state of this window. Changes to finished when ready to close.
	WndResultState _currentState;
};

