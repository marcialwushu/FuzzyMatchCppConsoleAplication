
#ifdef CONSOLEAPPLICATIONCPP_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

#include <string>

int DLL fuzzyMatch(std::string, std::string, double);
