#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "log.h"

void do_split_cmd(char cmd[], char ** cmdout){
    char ** cmdout_ptr = cmdout;
    char * token;

    token = strtok(cmd, " ");
    if(!token)
        return;

    *cmdout_ptr = (char *)malloc(strlen(token) + 1);
    memcpy(*cmdout_ptr, token, strlen(token));
    cmdout_ptr++;

    while((token = strtok(NULL, " "))){
        *cmdout_ptr = (char *)malloc(strlen(token) + 1);
        memcpy(*cmdout_ptr, token, strlen(token));
        cmdout_ptr++;
    }
}

void do_print_cmdlist(char ** cmdlist){
    for(char * c=*cmdlist; c; c=*++cmdlist)
        BSHELL_LOG_DEBUG("Element: %s", c);
}