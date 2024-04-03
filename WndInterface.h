//
// Created by Tiffanie Lim on 12/12/23.
//

#pragma once

#include <SFML/Graphics.hpp>

//states available for returning from WndInterface::getResultState().
enum WndResultState { NothingState, Finished, Restart, Menu, Quit };

class WndInterface
{
public:
	WndInterface(sf::IntRect bounds) : _bounds(bounds), _isEnabled(true) {};

	virtual ~WndInterface() = default;

	virtual void update(const float deltaTime) = 0;

	virtual void draw(sf::RenderWindow& renderWindow) const = 0;

	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) {};

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) {};

	virtual void handleKeyInput(const sf::Keyboard::Key key) {};

	void setEnabled(bool enabled) { _isEnabled = enabled; };

	bool isEnabled() const { return _isEnabled; }

	//by default this method returns WndResultState::Nothing unless overriden
	virtual WndResultState getResultState() const { return WndResultState::NothingState; };

protected:
	//bounds of this interface
	sf::IntRect _bounds;
	
	//state of whether the object is enabled so it can be used for managing updates
	bool _isEnabled;
};

