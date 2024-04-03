//
// Created by Tiffanie Lim on 12/8/23.
//

#pragma once

#include "HistogramBar.h"
#include <vector>

class HorizontalHistogram
{
public:
	//initialises the data into the bounds and optionally highlights one of the bar
	HorizontalHistogram(const sf::IntRect& bounds, const sf::Font& font, std::vector<std::pair<int, int>> data, const int highlightIndex);
	virtual ~HorizontalHistogram() = default;

	//draws all the bars.
	void draw(sf::RenderWindow & renderWindow) const;

private:
	//the collection of bars to be drawn
	std::vector<std::unique_ptr<HistogramBar>> _bars;
};

