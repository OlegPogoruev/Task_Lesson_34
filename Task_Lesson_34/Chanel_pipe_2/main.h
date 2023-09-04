
#include <stdio.h>
#include <string.h> // For strncpy





#define STAT_OK           0
#define STAT_ERROR        1




#define MAX_LEN_COMMAND        32


struct st_proces_param{
    char array_comand[MAX_LEN_COMMAND];
    int len;
    int status;
};
