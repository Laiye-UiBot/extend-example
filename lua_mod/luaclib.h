#pragma once

#ifdef WIN32

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#define DLLEXPORT extern "C" __declspec(dllexport)

#endif

#define EXTERN_DEF extern

