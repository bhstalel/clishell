
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"
#include "log.h"
#include "exec.h"

#define PROMPT      "bshell> "
#define MAX_BUFFER  128
#define INPUT       stdin

size_t do_prepare_cmd(char cmd[]){
    printf(PROMPT);
    fgets(cmd, MAX_BUFFER, INPUT);
    size_t length = strlen(cmd) - 1;
    /* Remove \n */
    cmd[strcspn(cmd, "\n")] = 0;
    BSHELL_LOG_DEBUG("Got command: %s, with length: %ld", cmd, length);
    return length;
}

int main(int argc, char **argv){

    /* Check if some prompt is provided */

    /**
     * Check if a prompt is provided
     * Start a while loop
     * Get input from the user
     * Split the input
     * Construct the args list
     * Fork and exec the command
     * Wait for the command to finish
     * = Add background execution !
     * = Add pipeline mechanism
     * 
     */
    while(1){
        char cmd[MAX_BUFFER];
        size_t len = do_prepare_cmd(cmd);

        if(!len)
            continue;

        if(len > 1){

            if(!strcmp(cmd, "exit"))
                break;

            BSHELL_LOG_DEBUG("Length: %ld", len);
            char ** cmdout = (char **)malloc(sizeof(char *) * 50);
            do_split_cmd(cmd, cmdout);
            do_print_cmdlist(cmdout);
            do_exec_cmd(cmdout);
        }

    }

}