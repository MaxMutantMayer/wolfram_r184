#include "OutputColorizer.hpp"

#include <windows.h>

#define YELBG 236
#define RESET  15

namespace wolfram_r184
{
namespace colorizer
{

HANDLE g_consoleHandle;

void Init(void)
{
	g_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	ResetOutputColor();
}

void ChangeToYellowBackground(void)
{
	SetConsoleTextAttribute(g_consoleHandle, YELBG);
}

void ResetOutputColor(void)
{
	SetConsoleTextAttribute(g_consoleHandle, RESET);
}

} // namespace colorizer
} // namespace wolfram_r184
