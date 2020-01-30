#ifndef POLYGON_CORE_H
#define POLYGON_CORE_H

#if defined(_WIN32) || defined(_WIN64)
    #define BUILD_SYSTEM_WINDOWS
#else
    #error "Only Windows supported for now!"
#endif //_WIN32 || _WIN64

#if defined(BUILD_SYSTEM_WINDOWS)
    #if defined(POLYGON_ENGINE_EXPORTS)
        #define POLYGON_ENGINE_API __declspec(dllexport)
    #else
        #define POLYGON_ENGINE_API __declspec(dllimport)
    #endif
#endif // BUILD_SYSTEM_WINDOWS

#endif // POLYGON_CORE_H