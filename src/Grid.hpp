#ifndef WOLFRAMR184_GRID_H
#define WOLFRAMR184_GRID_H

#include <bitset>

namespace wolfram_r184
{

const size_t GRID_SIZE = 30;

class Grid
{
public:
	Grid();

	/*
	 * Performs single transition of all cells
	 */
	void DoTransition(void);

	/*
	 * Prints grid in colored output
	 */
	void Print(void) const;

private:
	/*
	 * Generate random initial states for cells
	 */
	void Init(void);

	// Use double buffering for separate reading/writing
	std::bitset<GRID_SIZE> m_grid[2];

	// Index to current grid
	uint8_t m_currentGrid;
};

} // namespace wolfram_r184

#endif // !WOLFRAMR184_GRID_H
