/*
 * Wolfram R184
 *
 * Author:	Maximilian Mayer
 * License:	MIT (see LICENSE file)
 */

#include <stdio.h>

#include "CellularAutomaton.hpp"
#include "InputController.hpp"

int main(int argc, char* argv[])
{
	// Handle input arguments
	size_t transitions = 0;
	if (!wolfram_r184::input_controller::ParseInputArguments(argc, argv,
		transitions))
	{
		fprintf(stderr, "usage: wolfram_r184 <NumberOfTransitions>\n");
		return 1;
	}

    wolfram_r184::CellularAutomaton automaton;
	automaton.Run(transitions);

	return 0;
}
