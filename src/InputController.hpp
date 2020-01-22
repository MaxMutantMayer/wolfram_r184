#ifndef WOLFRAMR184_INPUTCONTROLLER_H
#define WOLFRAMR184_INPUTCONTROLLER_H

#include <stdlib.h>

namespace wolfram_r184
{
namespace input_controller
{

/*
 * Validates program arguments and sets 'out_transtitions'
 * \return True if arguments are valid
 */
bool ParseInputArguments(int argc, char* argv[], size_t& out_transitions);

} // namespace input_controller
} // namespace wolfram_r184

#endif // !WOLFRAMR184_INPUTCONTROLLER_H
