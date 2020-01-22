#include "InputController.hpp"

#include <sstream>
#include <stdio.h>

namespace wolfram_r184
{
namespace input_controller
{

bool ParseInputArguments(int argc, char* argv[], size_t& out_transitions)
{
	if (argc != 2)
		return false;

	// Convert given argument to size_t and validate it
	std::istringstream ss(argv[1]);
	if (!(ss >> out_transitions) || !ss.eof())
	{
		fprintf(stderr, "Invalid input: %s\n\n", argv[1]);
		return false;
	}

	return true;
}

} // namespace input_controller
} // namespace wolfram_r184
