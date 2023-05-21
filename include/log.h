#ifndef LOG_H
#define LOG_H

#define RED     "\033[1;31m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

#define BSHELL_LOG_INFO(msg, ...) \
        fprintf(stdout, "[INFO] %s:%s:%i (" msg ")\n", \
        __FILE__, __func__, __LINE__, ##__VA_ARGS__)

#ifdef ENABLE_LOG_DEBUG
#define BSHELL_LOG_DEBUG(msg, ...) \
        fprintf(stdout, BLUE "[DEBUG] %s:%s:%i (" msg ")" RESET "\n", \
        __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#else
#define BSHELL_LOG_DEBUG(msg, ...) /* Do nothing */
#endif

#define BSHELL_LOG_ERROR(msg, ...) \
        fprintf(stderr, RED "[ERROR] %s:%s:%i (" msg ")" RESET "\n", \
        __FILE__, __func__, __LINE__, ##__VA_ARGS__)


#endif /* LOG_H */