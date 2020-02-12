#ifndef POLYGON_ASSERTION_H
#define POLYGON_ASSERTION_H


#if defined(_DEBUG)
    #if defined(BUILD_SYSTEM_WINDOWS)
        #define DEBUG_BREAK __debugbreak()
    #else
        #include <signal.h>
        #if defined(SIGTRAP)
            #define DEBUG_BREAK raise(SIGTRAP)
        #else 
            #define DEBUG_BREAK raise(SIGABRT)
        #endif //SIGTRAP
    #endif //BUILD_SYSTEM_WINDOWS
#else
    #define DEBUG_BREAK 
#endif //_DEBUG


#if defined(_DEBUG)
    #include "Core/Logger/PLogger.h"
    #define POLYGON_ASSERT_ERROR(cond, ...)  if(!(cond)) {  POLYGON_LOG_CRITICAL(__VA_ARGS__); DEBUG_BREAK; }
    #define POLYGON_ASSERT_WARNING(cond, ...) if(!(cond)) { POLYGON_LOG_WARNING(__VA_ARGS__); }
#else 
    #define POLYGON_ASSERT_ERROR(cond, ...) 
    #define POLY_ASSERT_WARNING(cond, ...)
#endif //_DEBUG

#endif // POLYGON_ASSERTION_H