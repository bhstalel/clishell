#ifndef EXEC_H
#define EXEC_H

/**
 * @brief Execute a shell command via execve
 * 
 * @param cmdout The command to execute
 * @return The exit code of the command
 */
int do_exec_cmd(char ** cmdout);

#endif /* EXEC_H */