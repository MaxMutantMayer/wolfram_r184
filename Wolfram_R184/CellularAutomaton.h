#ifndef __CELLULARAUTOMATON_H__
#define __CELLULARAUTOMATON_H__

#include "Grid.h"

class CellularAutomaton
{
public:
	CellularAutomaton();
	~CellularAutomaton();

	// Performs N transitions of automaton with specified number
	void run(size_t numberOfTransitions);

private:
	Grid m_grid;
};

#endif // !__CELLULARAUTOMATON_H__
