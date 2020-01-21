/*
 * Wolfram R184
 *
 * Author:	Maximilian Mayer
 * License:	MIT (see LICENSE file)
 */

#include "CellularAutomaton.hpp"

const size_t DEFAULT_TRANSITIONS = 20;

int main(int argc, char* argv[])
{
    wolfram_r184::CellularAutomaton automaton;
	automaton.Run(DEFAULT_TRANSITIONS);

	return 0;
}
