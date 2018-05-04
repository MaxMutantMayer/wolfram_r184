#include "Grid.h"

#include <random>
#include "Windows.h"

#include "TransitionLookUpTable.h"

// Create Mersenne Twister engine with random device as seed
// Additionally use int distribution for 0 & 1 states
static std::random_device rd;
static std::mt19937_64 engine(rd()); 
static std::uniform_int_distribution<> distribution(0, 1);

Grid::Grid()
	: m_currentGrid(0)
{
	init();
}

Grid::~Grid()
{
}

void Grid::doTransition(void)
{
	uint8_t cellState = 0;

	// Do transition of all values
	for (size_t i = 0; i < AutomatonDefines::GRID_SIZE; ++i)
	{
		cellState = 0;

		// Handle edge cases -> left and right border cell
		if (i != 0)
		{
			cellState |= static_cast<uint8_t>(m_grid[m_currentGrid][i - 1]);
		}

		cellState |= static_cast<uint8_t>(m_grid[m_currentGrid][i]) << 1;

		if (i < AutomatonDefines::GRID_SIZE - 1)
		{
			cellState |= static_cast<uint8_t>(m_grid[m_currentGrid][i + 1]) << 2;
		}

		// Receive new value from lookup table and write to back buffered grid
		m_grid[!m_currentGrid][i] = TransitionLookUpTable::TABLE.at(cellState);
	}

	// Additionally add random state to cell at position zero if its 0 in current grid
	if (m_grid[m_currentGrid][0] == 0)
	{
		m_grid[!m_currentGrid][0] = distribution(engine);
	}

	// Switch grids after doing all transitions
	m_currentGrid = !m_currentGrid;
}

void Grid::printGrid(void)
{
	// Get console handle
	const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	for (size_t i = 0; i < AutomatonDefines::GRID_SIZE; ++i)
	{
		if (m_grid[m_currentGrid][i])
		{
			// Set yellow background color for cells with state 1
			SetConsoleTextAttribute(console, 236);
		}
		else
		{
			// Use default background for cells with state 0
			SetConsoleTextAttribute(console, 15);
		}
		printf("  ");
	}
	
	// Set console text color back to default
	SetConsoleTextAttribute(console, 15);
	printf("\n");
}

void Grid::init(void)
{
	// Initialize grid with random states 
	for (size_t i = 0; i < AutomatonDefines::GRID_SIZE; ++i)
	{
		m_grid[m_currentGrid][i] = distribution(engine);
	}
}
