#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "log.h"

int do_split_cmd(char cmd[], char ** cmdout){
    char ** cmdout_ptr = cmdout;
    char * token;
    int size = 0;

    token = strtok(cmd, " ");
    *cmdout_ptr = (char *)malloc(strlen(token) + 1);
    memcpy(*cmdout_ptr, token, strlen(token));
    cmdout_ptr++;
    size++;

    while((token = strtok(NULL, " "))){
        *cmdout_ptr = (char *)malloc(strlen(token) + 1);
        memcpy(*cmdout_ptr, token, strlen(token));
        cmdout_ptr++;
        size++;
    }

    BSHELL_LOG_DEBUG("Splited command (%s) => size (%d)", cmd, size);
    return size;
}

void do_print_cmdlist(char ** cmdlist){
    for(char * c=*cmdlist; c; c=*++cmdlist)
        BSHELL_LOG_DEBUG("Element: %s", c);
}