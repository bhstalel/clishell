#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

#include "log.h"

int do_exec_cmd(char ** cmdout, int size){

    /* Check if the command must be run in the background */
    /* Get last element of the command */
    BSHELL_LOG_DEBUG("Checking last element of command with size: %d", size);
    char * lastelem = *(cmdout+size-1);
    size_t lastelem_size = strlen(lastelem);
    BSHELL_LOG_DEBUG("Last element of the command is: %s", lastelem);

    if(((lastelem_size == 1) && (*lastelem == '&')) || \
        ((lastelem_size >  1) && (*(lastelem+lastelem_size-1) == '&')))
        BSHELL_LOG_DEBUG("Running process in background ...");

    pid_t pid = fork();

    if(pid < 0){
        BSHELL_LOG_ERROR("Could not execute fork");
    }else if(pid > 0){
        /* Parent process; wait for the child to finish */
        int status;
        waitpid(pid, &status, 0);
        if(status)
            BSHELL_LOG_ERROR("Execution failed with code: %d", status);
        return status;
    }else{
        /* Child process */
        printf("\n");
        execvp(*cmdout, cmdout);
    }
}
