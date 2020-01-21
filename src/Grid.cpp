#include "Grid.hpp"

#include <random>

#include "OutputColorizer.hpp"
#include "TransitionLookupTable.hpp"

static std::random_device rd;
static std::mt19937_64 engine(rd());
static std::uniform_int_distribution<> distribution(0, 1);

namespace wolfram_r184
{

Grid::Grid()
	: m_currentGrid(0)
{
	Init();
	colorizer::Init();
}

void Grid::DoTransition(void)
{
	uint8_t cellState = 0;

	// Do transition of all values
	for (size_t i = 0; i < GRID_SIZE; ++i)
	{
		cellState = 0;

		// Handle edge cases -> left and right border cell
		if (i != 0)
		{
			cellState |= static_cast<uint8_t>(m_grid[m_currentGrid][i - 1]);
		}

		cellState |= static_cast<uint8_t>(m_grid[m_currentGrid][i]) << 1;

		if (i < GRID_SIZE - 1)
		{
			cellState |=
				static_cast<uint8_t>(m_grid[m_currentGrid][i + 1]) << 2;
		}

		// Receive new value from lookup table and write to back buffered grid
		m_grid[!m_currentGrid][i] = TransitionLookupTable::TABLE.at(cellState);
	}

	// Additionally add random state to empty cells at position zero
	if (m_grid[m_currentGrid][0] == 0)
	{
		m_grid[!m_currentGrid][0] = distribution(engine);
	}

	// Switch grids after doing all transitions
	m_currentGrid = !m_currentGrid;
}

void Grid::Print(void) const
{
	for (size_t i = 0; i < GRID_SIZE; ++i)
	{
		// Use yellow background for cells with state 1 and
		// default background for cells with state 0
		m_grid[m_currentGrid][i]
			? colorizer::ChangeToYellowBackground()
			: colorizer::ResetOutputColor();

		printf("  ");
	}

	colorizer::ResetOutputColor();
	printf("\n");
}

void Grid::Init(void)
{
	for (size_t i = 0; i < GRID_SIZE; ++i)
	{
		m_grid[m_currentGrid][i] = distribution(engine);
	}
}

} // namespace wolfram_r184
