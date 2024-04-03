//
// Created by Tiffanie Lim on 12/9/23.
//
#pragma once
#include "WndInterface.h"
#include "Button.h"

class KeyboardWnd :
	public WndInterface
{
public:
	//initialises the keyboard to centre itself at the bottom middle of bounds
	KeyboardWnd(const sf::IntRect& bounds, const sf::Font& font);
	virtual ~KeyboardWnd() = default;

	virtual void update(const float deltaTime) override {};

	//draws all the buttons on the keyboard
	virtual void draw(sf::RenderWindow & renderWindow) const override;

	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	//gets the value of actionID and resets it to default -1
	int getActionIDReset();

	//applies rule colours to keyboard keys
	void applyRules(std::vector<std::string> rules);

private:
	//list of buttons on the keyboard
	std::vector<Button> _buttons;

	//current actionID
	int _actionID;

	//initialises all the buttons for the keyboard
	void initialiseButtons(const sf::Font& font);
};

