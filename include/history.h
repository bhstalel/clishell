#ifndef HISTORY_H
#define HISTORY_H

#include "log.h"

#define HISTORY_BUFF_SIZE   10

/**
 * @brief Add new command to the history buffer
 * 
 * @param cmd       The new command
 * @param history   The history buffer
 */
void do_process_history(char * cmd, char ** history);

/**
 * @brief Print full history
 */
void do_print_history();

#endif /* HISTORY_DEF */