#ifndef POLYGON_LOGGER_H
#define POLYGON_LOGGER_H

#if defined(_DEBUG)
    #include "spdlog/spdlog.h"
    #include "spdlog/sinks/basic_file_sink.h"
    #define POLYGON_LOG_INFO(...) spdlog::info(__VA_ARGS__)
    #define POLYGON_LOG_WARN(...) spdlog::warn(__VA_ARGS__)
    #define POLYGON_LOG_ERROR(...) spdlog::error(__VA_ARGS__)
    #define POLYGON_LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)
#else
    #define POLYGON_LOG_INFO(...)
    #define POLYGON_LOG_WARN(...) 
    #define POLYGON_LOG_ERROR(...) 
    #define POLYGON_LOG_CRITICAL(...) 
#endif // _DEBUG

#endif // POLYGON_LOGGER_H