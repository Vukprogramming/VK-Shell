#ifndef OS_DETECT_H
#define OS_DETECT_H

static inline const char* getOS() {
#ifdef _WIN32
    return "Windows";
#elif __linux__
    return "Linux";
#elif __APPLE__
    return "macOS";
#elif __unix__
    return "Unix";
#else
    return "Unknown OS";
#endif
}

#endif