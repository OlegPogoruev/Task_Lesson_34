
#include <stdio.h>
#include <string.h> // For strncpy



/*
       #include <sys/types.h>
       #include <sys/stat.h>

       #include <fcntl.h>           // Definition of AT_* constants
       #include <sys/stat.h>
*/


#define MODE_PRINTF       0
#define MODE_COMPARE      1



#define STAT_OK           0
#define STAT_ERROR        1


#define GLUE_GAP_OFF      0
#define GLUE_GAP_ON       1






#define MAX_LEN_NAME        255
#define MAX_LEN_PARAM       32
#define MAX_NUMBER_PARAM    2


struct st_proces_param{
    char array_name[MAX_LEN_NAME];
    char array_param_1[MAX_LEN_PARAM];
    char array_param_2[MAX_LEN_PARAM];
    int status;
};




