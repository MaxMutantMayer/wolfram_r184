#ifndef __GRID_H__
#define __GRID_H__

#include <bitset>

#include "AutomatonDefines.h"

class Grid
{
public:
	Grid();
	~Grid();

	// Performs single transition of all cells
	void doTransition(void);

	// Prints grid in colored output
	void printGrid(void);

private:
	// Generates random states in grid
	void init(void);

	// Use double buffering for separate reading/writing
	std::bitset<AutomatonDefines::GRID_SIZE> m_grid[2];

	// Index to current grid
	uint8_t m_currentGrid;
};

#endif __GRID_H__
