/*
 * main.c
 */
//#include <stdio.h>
#include "SoProces_2.h"


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
        printf("               -'hex' - print char to hex\n");
        printf("               -'dec' - print char to dec\n");
        exit(EXIT_SUCCESS);
    }

    if(NULL == argv[1]){printf("not define Param_2\n");exit(EXIT_SUCCESS);}

    if (strcmp ("hex", argv[0])==0)
    {
        int i = 0;
        while(0 != argv[1][i])
        {
            printf("%c = 0x%x\n", argv[1][i], argv[1][i]);
            ++i;
        }
        exit(EXIT_SUCCESS);
    }


    if (strcmp ("dec", argv[0])==0)
    {
        int i = 0;
        while(0 != argv[1][i])
        {
            printf("%c = %d\n", argv[1][i], argv[1][i]);
            ++i;
        }
        exit(EXIT_SUCCESS);
    }

    printf("Error Param_1 = ");
    printf("%s\n", argv[0]);
    exit(EXIT_SUCCESS);

}
