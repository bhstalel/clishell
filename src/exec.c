#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#include "log.h"

int do_exec_cmd(char ** cmdout){

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
        execvp(*cmdout, cmdout);
    }
}
