#ifndef COMMAND_H
#define COMMAND_H

#define PROMPT      "clishell> "
#define MAX_BUFFER  128
#define INPUT       stdin

/**
 * @brief  Get command from input and process it
 * 
 * @param cmd       The command output buffer
 * @return size_t   The length of the command
 */
size_t do_prepare_cmd(char cmd[]);

#endif /* COMMAND_H */