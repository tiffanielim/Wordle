//
// Created by Tiffanie Lim on 12/9/23.
//

#include "KeyboardWnd.h"

KeyboardWnd::KeyboardWnd(const sf::IntRect& bounds, const sf::Font& font)
	: WndInterface(bounds)
{
	initialiseButtons(font);
	_actionID = -1;
}

void KeyboardWnd::draw(sf::RenderWindow & renderWindow) const
{
	for (const auto& button : _buttons) {
		button.draw(renderWindow);
	}
}

void KeyboardWnd::handleMousePress(const sf::Vector2i & mousePosition, bool isLeft)
{
	for (auto& button : _buttons) {
		if (button.isPositionInside(mousePosition)) {
			_actionID = button.getActionID();
			break;
		}
	}
}

void KeyboardWnd::handleMouseMove(const sf::Vector2i & mousePosition)
{
	for (auto& button : _buttons) {
		button.setHovering(button.isPositionInside(mousePosition));
	}
}

int KeyboardWnd::getActionIDReset()
{
	int oldActionID = _actionID;
	_actionID = -1;
	return oldActionID;
}

void KeyboardWnd::applyRules(std::vector<std::string> rules)
{
	for (auto rule : rules) {
		for (int i = 0, pos = 0; i < rule.length(); ++i, ++pos) {
			int colourID = 1;
			// Exists at position with exact match
			if (rule.at(i) == '*') {
				i++;
				colourID = 3;
			}
			// One or more in string but not at pos
			else if (rule.at(i) == '#') {
				i++;
				colourID = 2;
			}

			int letterCasted = static_cast<int>(rule.at(i));
			auto button = std::find_if(_buttons.begin(), _buttons.end(),
				[&](Button b) { return b.getActionID() == letterCasted; });
			if (button != _buttons.end()) {
				button->applyColourID(colourID);
			}
		}
	}
}

void KeyboardWnd::initialiseButtons(const sf::Font& font)
{
	std::vector<std::string> buttonText{ "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Check", "Z", "X", "C", "V", "B", "N", "M", "<" };

	int buttonWidth = 60;
	int buttonHeight = 60;

	int midX = ((buttonWidth + 10) * (3 + 8) - 10) / 2;
	int actualLeft = _bounds.left + _bounds.width / 2 - midX;

	int posX = actualLeft + midX - ((buttonWidth + 10) * (10) - 10) / 2;
	int posY = _bounds.top + _bounds.height - (buttonHeight + 15) * 3;
	int i = 0;

	//top row Q to P
	for (; i < 10; i++, posX += buttonWidth + 10) {
		_buttons.emplace_back(Button(sf::IntRect(posX, posY, buttonWidth, buttonHeight), buttonText.at(i), static_cast<int>(buttonText.at(i).at(0)), font));
	}
	
	posX = actualLeft + midX - ((buttonWidth + 10) * (9) - 10) / 2;
	posY += 10 + buttonHeight;
	//middle row
	for (; i < 19; i++, posX += buttonWidth + 10) {
		_buttons.emplace_back(Button(sf::IntRect(posX, posY, buttonWidth, buttonHeight), buttonText.at(i), static_cast<int>(buttonText.at(i).at(0)), font));
	}
	
	posX = actualLeft;
	posY += 10 + buttonHeight;
	//special case for "Check"
	_buttons.emplace_back(Button(sf::IntRect(posX, posY, buttonWidth*3, buttonHeight), buttonText.at(i), 1, font));
	i++;
	posX += buttonWidth * 3 + 10;
	//bottom row
	for (; i < buttonText.size(); i++, posX += buttonWidth + 10) {
		_buttons.emplace_back(Button(sf::IntRect(posX, posY, buttonWidth, buttonHeight), buttonText.at(i), static_cast<int>(buttonText.at(i).at(0)), font));
	}
}
