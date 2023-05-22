#include <sys/types.h>
#include <stdio.h>
#include <string.h>

#include "log.h"
#include "command.h"

size_t do_prepare_cmd(char cmd[]){
    fgets(cmd, MAX_BUFFER, INPUT);
    size_t length = strlen(cmd) - 1;
    /* Remove \n */
    cmd[strcspn(cmd, "\n")] = 0;
    if(length)
        BSHELL_LOG_DEBUG("Got command: %s, with length: %ld", cmd, length);
    return length;
}