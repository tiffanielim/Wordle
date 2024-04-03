//
// Created by Tiffanie Lim on 12/9/23.
//

#pragma once

#include <vector>
#include <random>

class WordDatabase
{
public:
	//initialises the word database with the associated file
	WordDatabase(std::default_random_engine& randomEngine);
	virtual ~WordDatabase() = default;

	//returns true if the word specified is a word in the database
	bool isValidWord(const std::string& word) const;

	//returns a random word from the database
	std::string getRandomWord() const;

private:
	//the database
	std::vector<std::string> _words;

	//shared randomEngine used for all the randomisation
	std::default_random_engine& _randomEngine;

	//loads the word list in and sorts in alphabetically
	void loadDatabase();
};

