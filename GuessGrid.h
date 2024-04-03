//
// Created by Tiffanie Lim on 12/7/23.
//
#pragma once
#include "WndInterface.h"
#include "PuzzleLetter.h"

class GuessGrid :
	public WndInterface
{
public:
	//initialises the full grid as an empty set of elements waiting to be filled
	GuessGrid(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution, const int maxGuesses);
	virtual ~GuessGrid() = default;

	virtual void update(const float deltaTime) override {};

	//draws the grid of guessed letters.
	virtual void draw(sf::RenderWindow & renderWindow) const override;

	virtual void handleKeyInput(const sf::Keyboard::Key key) override;

	//inserts the specified letter if there is room in the current attempt
	void tryInsertLetter(const char letter);

	//removes one letter if possible (does nothing if there is no letter for the current attempt to remove)
	void backSpace();

	//tests the solution
	void checkSolution();

	//check if the solution has been reached
	bool isSolved() const;

	//check if the user has run out of guesses
	bool hasMoreGuesses() const;

	//gets expressions for all the rules for solving based on guesses
	std::vector<std::string> getAllRules() const;

	//get and reset the changed via keys state.
	bool getKeyCheckReset();

	//gets the solution that the user is matching
	std::string getSolution() const;

	//gets a string representing the finished puzzle state.
	std::string getShareString() const;

private:
	//the collection of letters
	std::vector<std::vector<PuzzleLetter>> _guessLetters;

	//position for next insertion
	int _insertPosition;

	//position for the current word
	int _currentWordIndex;
	
	//when true it means the solution has been found
	bool _solved;

	//used keys to check
	bool _usedKeyCheck;

	//the solution to check against
	const std::string _solution;

	//creates an empty grid based on the specified size
	void initialiseAllGuesses(const sf::Font & font, const int wordLength, const int maxGuesses);
};

