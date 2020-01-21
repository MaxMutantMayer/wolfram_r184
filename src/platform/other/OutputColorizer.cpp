#include "OutputColorizer.hpp"

#include <stdio.h>

#define YELBG "\x1B[103m"
#define RESET "\x1B[0m"

namespace wolfram_r184
{
namespace colorizer
{

void Init(void)
{
	ResetOutputColor();
}

void ChangeToYellowBackground(void)
{
    printf(YELBG);
}

void ResetOutputColor(void)
{
	printf(RESET);
}

} // namespace colorizer
} // namespace wolfram_r184
