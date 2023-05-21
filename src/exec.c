#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#include "log.h"

void do_exec_cmd(char ** cmdout){

    pid_t pid = fork();

    if(pid < 0)
        BSHELL_LOG_DEBUG("Could not execute fork");
    else if(pid > 0){
        /* Parent process; wait for the child to finish */
        wait(NULL);
    }else{
        /* Child process */
        execvp(*cmdout, cmdout);
    }
}
