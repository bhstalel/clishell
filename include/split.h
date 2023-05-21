#ifndef SPLIT_H
#define SPLIT_H

/**
 * @brief Split a string by the space delimiter
 * 
 * @param cmd       The string command to split
 * @param cmdout    The double pointer output result holder
 */
void do_split_cmd(char cmd[], char ** cmdout);

/**
 * @brief Print the final parsed command
 * 
 * @param cmdlist The pointer to pointer of the parsed command
 */
void do_print_cmdlist(char ** cmdlist);

#endif /* SPLIT_H */