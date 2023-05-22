#include <stdlib.h>
#include <string.h>

#include "history.h"
#include "log.h"

int history_index = 0;

void do_process_history(char * cmd, char ** history){
    BSHELL_LOG_DEBUG("Processing history for command: (%s)", cmd);

    if(history_index >= HISTORY_BUFF_SIZE){
        /* Translate elements */
        history_index = HISTORY_BUFF_SIZE - 1;
        for(int elem=0; elem<history_index; elem++)
            *(history+elem) = *(history+elem+1); 
    }

    BSHELL_LOG_DEBUG("Adding new command(%s) to history with index(%d) BUFF(%d)", \
                         cmd, history_index, HISTORY_BUFF_SIZE);
    *(history+history_index) = (char *)malloc(strlen(cmd));
    memcpy(*(history+history_index), cmd, strlen(cmd));
    history_index++;
}

void do_print_history(char ** history){
    printf("\n[HISTORY]\n");
    while(*history != NULL){
        printf("\t- %s\n", *history);
        history++;
    }
    printf("\n");
}