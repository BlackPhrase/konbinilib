#include "konbini/platformtypes.hpp"

#if KONBINI_PLATFORM == KONBINI_PLATFORM_WINDOWS
	#define EXPORT [[dllexport]]
#else
	#define EXPORT [[visibility("default")]]
#endif

#define C_EXPORT extern "C" EXPORT

C_EXPORT bool GetStubAPI()
{
	return true;
};