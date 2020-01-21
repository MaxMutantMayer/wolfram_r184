#ifndef WOLFRAMR184_TRANSITIONLOOKUPTABLE_H
#define WOLFRAMR184_TRANSITIONLOOKUPTABLE_H

#include <map>

namespace wolfram_r184
{
namespace TransitionLookupTable
{

// Lookup table for cell state transitions
static const std::map<uint8_t, uint8_t> TABLE =
{
    {0b000, 0}, // OOO = O
    {0b001, 1}, // XOO = X
    {0b010, 0}, // OXO = O
    {0b100, 0}, // OOX = O
    {0b011, 0}, // XXO = O
    {0b101, 1}, // XOX = X
    {0b110, 1}, // OXX = X
    {0b111, 1}  // XXX = X
};

} // namespace TransitionLookupTable
} // namespace wolfram_r184


#endif // !WOLFRAMR184_TRANSITIONLOOKUPTABLE_H
