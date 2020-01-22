#ifndef WOLFRAMR184_TRANSITIONLOOKUPTABLE_H
#define WOLFRAMR184_TRANSITIONLOOKUPTABLE_H

#include <map>

namespace wolfram_r184
{
namespace transition_lookup_table
{

// Lookup table for cell state transitions
const std::map<uint8_t, uint8_t> TABLE =
{
    {static_cast<uint8_t>(0b000), static_cast<uint8_t>(0)}, // OOO = O
    {static_cast<uint8_t>(0b001), static_cast<uint8_t>(1)}, // XOO = X
    {static_cast<uint8_t>(0b010), static_cast<uint8_t>(0)}, // OXO = O
    {static_cast<uint8_t>(0b100), static_cast<uint8_t>(0)}, // OOX = O
    {static_cast<uint8_t>(0b011), static_cast<uint8_t>(0)}, // XXO = O
    {static_cast<uint8_t>(0b101), static_cast<uint8_t>(1)}, // XOX = X
    {static_cast<uint8_t>(0b110), static_cast<uint8_t>(1)}, // OXX = X
    {static_cast<uint8_t>(0b111), static_cast<uint8_t>(1)}  // XXX = X
};

} // namespace transition_lookup_table
} // namespace wolfram_r184


#endif // !WOLFRAMR184_TRANSITIONLOOKUPTABLE_H
