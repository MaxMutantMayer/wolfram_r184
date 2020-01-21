#include "CellularAutomaton.hpp"

namespace wolfram_r184
{

void CellularAutomaton::Run(size_t numberOfTransitions)
{
	m_grid.Print();
	for (size_t i = 0; i < numberOfTransitions; ++i)
	{
		m_grid.DoTransition();
		m_grid.Print();
	}
}

} // namespace wolfram_r184
