
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"
#include "log.h"
#include "exec.h"
#include "command.h"
#include "history.h"

int exit_status = 0;

int main(int argc, char **argv){

    /* Prepare the history buffer */
    char ** history = (char **)malloc(sizeof(char *) * HISTORY_BUFF_SIZE);

    /**
     * Check if a prompt is provided
     * OK Start a while loop
     * OK Get input from the user
     * OK Split the input
     * OK Construct the args list
     * OK Fork and exec the command
     * OK Wait for the command to finish:
     * = Test if wait if OK (if child completed OK) : Add return code to PROMPT ?
     * = Add background execution !
     * = Add pipeline mechanism
     * = Add History with circular buffer mechanism
     */
    while(1){
        char cmd[MAX_BUFFER];
        printf("%d | %s", exit_status, PROMPT);
        size_t len = do_prepare_cmd(cmd);

        /* Continue if no command is provided (Just an ENTER click)*/
        if(!len)
            continue;

        if(len > 1){

            /* Break the loop if "exit" command */
            if(!strcmp(cmd, "exit"))
                break;

            /* Print history */
            if(!strcmp(cmd, "history")){
                do_print_history(history);
                continue;
            }

            /* Process History with new command */
            do_process_history(cmd, history);

            BSHELL_LOG_DEBUG("Length: %ld", len);

            /* Split the input command by space */
            char ** cmdout = (char **)malloc(sizeof(char *) * 50);
            do_split_cmd(cmd, cmdout);
            do_print_cmdlist(cmdout);

            /* Execute command */
            printf("\n");
            exit_status = do_exec_cmd(cmdout);
            printf("\n");
        }

    }

}