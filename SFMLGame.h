//
// Created by Tiffanie Lim on 12/9/23.
//

#pragma once

#include "Game.h"

class SFMLGame
{
public:
	//initialises the game ready to start.
	SFMLGame();
	virtual ~SFMLGame() = default;

	//continues running the game until
	void gameLoop();

private:
	//the window used for the game until it ends
	sf::RenderWindow _window;

	//the font used throughout the game
	sf::Font _font;

	//reference to the Game used to manage all the interfaces within the game
	Game _game;

	//load the font
	static sf::Font loadFont();
};


