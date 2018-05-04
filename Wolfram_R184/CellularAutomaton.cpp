#include "CellularAutomaton.h"

CellularAutomaton::CellularAutomaton()
{
}

CellularAutomaton::~CellularAutomaton()
{
}

void CellularAutomaton::run(size_t numberOfTransitions)
{
	m_grid.printGrid();
	for (size_t i = 0; i < numberOfTransitions; ++i)
	{
		m_grid.doTransition();
		m_grid.printGrid();
	}
}
