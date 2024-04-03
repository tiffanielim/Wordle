//
// Created by Tiffanie Lim on 12/7/23.
//
#pragma once
#include "WndInterface.h"
#include <random>
#include "WordDatabase.h"
#include "PlayHistory.h"

class Game
{
public:
	//initialises the game with the Lobby
	Game(const sf::IntRect& gameBounds, const sf::Font& font);
	virtual ~Game();

	//updates the current state of the active window
	void update(const float deltaTime);

	//draws the current window
	void draw(sf::RenderWindow & renderWindow) const;

	//handles passing events on to the active interface
	void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft);

	//handles passing the mouse moved event to the active interface
	void handleMouseMove(const sf::Vector2i& mousePosition);

	//handles passing key pressed event to the active interface
	void handleKeyInput(const sf::Keyboard::Key key);

	// when true, the game should end
	bool getGameCloseRequested();

private:
	//bounds of the game area
	const sf::IntRect _bounds;

	//reference to the font
	const sf::Font& _font;

	//shared randomEngine used for all the randomisation
	std::default_random_engine _randomEngine;

	//reference to the current active interface
	WndInterface* _activeInterface;

	//reference to the current active overlay if one exists
	WndInterface* _activeOverlay;

	//when true, the game should end
	bool _terminateGame;

	//collection of words
	std::unique_ptr<WordDatabase> _wordDatabase;

	//the player's saved history
	std::unique_ptr<PlayHistory> _playHistory;
};
