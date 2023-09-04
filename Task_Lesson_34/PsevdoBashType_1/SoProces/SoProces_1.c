/*
 * main.c
 */
//#include <stdio.h>
#include "SoProces_1.h"


//#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

//printf("0 = %s\n", argv[0]);
//printf("1 = %s\n", argv[1]);
//printf("2 = %s\n", argv[2]);


    if(NULL == argv[0]){printf("not define Param_1\n");exit(EXIT_SUCCESS);}
    

    if (strcmp ("help", argv[0])==0)
    {
        printf("param_1 can be:\n");
        printf("               -'normal' - print string\n");
        printf("               -'revers' - revers print string\n");
        exit(EXIT_SUCCESS);
    }

    if(NULL == argv[1]){printf("not define Param_2\n");exit(EXIT_SUCCESS);}

    if (strcmp ("normal", argv[0])==0)
    {
        printf("%s\n", argv[1]);
        exit(EXIT_SUCCESS);
    }


    if (strcmp ("revers", argv[0])==0)
    {
        char temp_str[256];
        int i = 0;
        int j = 0;
        while(0 != argv[1][i]){++i;}
//        ++i;
        while(0 != i)
        {
            --i;
            temp_str[j] = argv[1][i];
            ++j;
        }
        temp_str[j] = 0;
        printf("%s\n", temp_str);
        exit(EXIT_SUCCESS);
    }

    printf("Error Param_1 = ");
    printf("%s\n", argv[0]);
    exit(EXIT_SUCCESS);

}
