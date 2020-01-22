#ifndef WOLFRAMR184_CELLULARAUTOMATON_H
#define WOLFRAMR184_CELLULARAUTOMATON_H

#include "Grid.hpp"

namespace wolfram_r184
{

class CellularAutomaton
{
public:
	CellularAutomaton(void) = default;

    /*
     * Perform N transitions on grid
     */
	void Run(size_t numberOfTransitions);

private:
	Grid m_grid;
};

} // namespace wolfram_r184

#endif // !WOLFRAMR184_CELLULARAUTOMATON_H
