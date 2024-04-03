//
// Created by Tiffanie Lim on 12/30/23.
//

#pragma once
#include <vector>
#include <string>

class PlayHistory
{
public:
	//loads the save data from the specified file or creates a new dataset.
	PlayHistory(const std::string& saveFileName);
	virtual ~PlayHistory() = default;

	//inserts into the history by incrementing the count by 1 if that element exists.
	void insertHistory(const int countToIncrement);

	//inserts a loss
	void insertHistoryLoss();

	//gets a reference to the history.
	const std::vector<std::pair<int, int>>& getHistory() const;

	//gets the total played games
	int getTotalPlayed() const;

	//gets the current streak of wins
	int getCurrentStreak() const;

	//gets the maximum win streak
	int getMaxStreak() const;

	//gets the win % as a whole number
	int getWinPercent() const;

private:
	//the history containing all saved values.
	std::vector<std::pair<int, int>> _playHistory;

	//total games played
	int _totalPlayed;

	//total games won
	int _totalWon;

	//current win streak
	int _currentStreak;

	//maximum streak
	int _maxStreak;

	//reference to the filename for saving history.
	std::string _saveFileName;

	//loads the file into the history.
	void loadFile();

	//saves the history into the file.
	void saveFile();

	//initialises a default dataset with 0s for everything.
	void initialiseDefault();
};

