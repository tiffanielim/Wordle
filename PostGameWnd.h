//
// Created by Tiffanie Lim on 12/30/23.
//

#pragma once
#include "WndInterface.h"
#include "Button.h"
#include "HorizontalHistogram.h"
#include "PlayHistory.h"

class PostGameWnd :
	public WndInterface
{
public:
	//initialises the window with details about the game and a choice to start a new game or quit.
	PostGameWnd(const sf::IntRect& bounds, const sf::Font& font, const std::string& solution, const bool wonGame, 
				const int attempts, const std::unique_ptr<PlayHistory>& playHistory, const std::string& shareStr);
	virtual ~PostGameWnd() = default;

	//does nothing
	virtual void update(const float deltaTime) override {};

	//draws the interface elements.
	virtual void draw(sf::RenderWindow & renderWindow) const override;

	virtual void handleMousePress(const sf::Vector2i& mousePosition, bool isLeft) override;

	virtual void handleMouseMove(const sf::Vector2i& mousePosition) override;

	//gets the WndResultState that changes from NothingState when the window is done.
	WndResultState getResultState() const override;

private:
	//changes when the post-game is finished.
	WndResultState _resultState;

	//buttons to choose what to do next
	std::vector<Button> _buttons;

	//background for only the interface
	std::unique_ptr<sf::RectangleShape> _background;

	//background to cover all elements
	std::unique_ptr<sf::RectangleShape> _fullScreenBackground;

	//title text
	std::unique_ptr<sf::Text> _titleText;

	//text showing the solution
	std::unique_ptr<sf::Text> _solutionText;

	//histogram showing how their result fits with their other victories.
	std::unique_ptr<HorizontalHistogram> _histogram;

	//text showing the total number of played games
	std::unique_ptr<sf::Text> _totalPlayedText;

	//text showing the win percent
	std::unique_ptr<sf::Text> _winPercentText;

	//text showing the current win streak
	std::unique_ptr<sf::Text> _currentStreakText;

	//text showing the best win streak
	std::unique_ptr<sf::Text> _maxStreakText;

	//text used to share the result
	std::string _shareStr;
};

