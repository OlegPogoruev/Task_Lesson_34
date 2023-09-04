


#include "main.h"


#include <stdlib.h>

       #include <sys/types.h>
       #include <sys/wait.h>


// feacher funktion fork()
#include <unistd.h>
#include <stdio.h>




#include <malloc.h>
#include <dirent.h>




#define MAX_LEN_INPUT_STR 4096



struct st_proces_param scan_input_string(char *str);
struct st_proces_param scan_input_array(char *str);


int gluing_strings(char* str_com, char* str_1, char* str_2);



int main(){



    struct st_proces_param data_to_execution;

    printf("enter name comand revers or normal\n");
    printf("than enter string\n");
    printf("\n for example: \n");
    printf("                revers horizont'\n");

    char input_string[MAX_LEN_INPUT_STR];
    int len;

    int fd1[2]; // Used to store two ends of first pipe
    int fd2[2]; // Used to store two ends of second pipe

    if (pipe(fd1) == -1) {fprintf(stderr, "Pipe Failed");return 1;}
    if (pipe(fd2) == -1) {fprintf(stderr, "Pipe Failed");return 1;}


    pid_t t;

    t=fork();
    if(t==-1){printf("Error fork Failed\n");return 1;}

//    while(1)
//    {
        if(!t)  // parent branch
        {
            close(fd1[0]); // Close reading end of first pipe

            while(1)
            {
                data_to_execution = scan_input_string(input_string);


                if(STAT_OK == data_to_execution.status)
                {

                   char temp_full_str[MAX_LEN_INPUT_STR];
                   int temp_len;
                   temp_len = gluing_strings(temp_full_str, data_to_execution.array_comand, input_string);

                    // Write input string and close writing end of first pipe.
                    write(fd1[1], temp_full_str, temp_len+1);
    //                wait(NULL);// Wait for child to send a string
/**/
                    if (strcmp (data_to_execution.array_comand, "exit")==0)
                    {
                        wait(NULL);// Wait for child to send a string
                        break;
                    }

                    // Read string from child, print it and close reading end.
                    read(fd2[0], input_string, MAX_LEN_INPUT_STR);

                    printf("%s\n", input_string);
                }
                else{printf("Error input\n");}

            }

        
 

            
        }
        else    // child brahch
        {
            close(fd1[1]); // Close writing end of first pipe
            
            while(1)
            {
            // Read a string using first pipe
            read(fd1[0], input_string, MAX_LEN_INPUT_STR);
            data_to_execution = scan_input_array(input_string);

            char temp_com_exe;
            temp_com_exe = 0;

            if (strcmp (data_to_execution.array_comand, "exit")==0)
            {
                exit(EXIT_SUCCESS);
                break;
            }

            if (strcmp (data_to_execution.array_comand, "normal")==0)
            {
                // Write concatenated string and close writing end
                input_string[data_to_execution.len] = 0;
                write(fd2[1], input_string, data_to_execution.len);
                temp_com_exe = 1;
            }

            ///////////////////////////////////////////////////
            if (strcmp (data_to_execution.array_comand, "revers")==0)
            {
                char temp_str[MAX_LEN_INPUT_STR];
//                memset(temp_str, 0, MAX_LEN_INPUT_STR);
                int i = 0;
                int j = 0;
                while(0 != input_string[i]){++i;}
            //   ++i;
                while(0 != i)
                {
                    --i;
                    temp_str[j] = input_string[i];
                    ++j;
                }
                temp_str[j] = 0;
                // Write concatenated string and close writing end
                write(fd2[1], temp_str, j);
                temp_com_exe = 1;
            }
            ///////////////////////////////////////////////////
            
            if(0 == temp_com_exe)
            {
                write(fd2[1], "Error comand\n", 13);
//                printf("Error comand\n");
            }



            }

        }
//    }


}







struct st_proces_param scan_input_string(char *str)
{

    struct st_proces_param st_temp;
    for(unsigned int i = 0; i < MAX_LEN_COMMAND; ++i){st_temp.array_comand[i] = 0;}
    st_temp.len = 0;
    st_temp.status = STAT_ERROR;

    int ch;
    unsigned char begin_wd = 0;
    unsigned int count_wd = 0;
    unsigned int count_char = 0;

    while ((ch = getchar()) != '\n')
    {
        if(0 == count_wd)
        {
            if(0 == begin_wd)
            {
                if(' ' != ch)
                {
                    if(0 == count_wd)
                    {
                        st_temp.array_comand[0] = ch;
                        count_char = 1;
                    }

                    begin_wd = 1;
//                    st_temp.status = STAT_OK;
                }
            }
            else
            {

                if(' ' == ch)
                {
                    begin_wd = 0;
                    ++count_wd;
                    if(MAX_LEN_COMMAND < count_wd)
                    {st_temp.status = STAT_ERROR;return st_temp;}
                }
                else
                {
                    if(0 == count_wd)
                    {
                        st_temp.array_comand[count_char] = ch;
                        ++count_char;
                        if(MAX_LEN_COMMAND <= count_char)
                        {st_temp.status = STAT_ERROR;return st_temp;}
                    }
                }
            }
        }
        else
        {
            (*(str + st_temp.len)) = ch;
            ++st_temp.len;
            if((MAX_LEN_INPUT_STR - MAX_LEN_COMMAND - 2) < st_temp.len)
            {
                st_temp.len = MAX_LEN_INPUT_STR - MAX_LEN_COMMAND;
                (*(str + MAX_LEN_INPUT_STR - MAX_LEN_COMMAND - 1)) = 0;
                return st_temp;
            }
        }

    }

    (*(str + st_temp.len)) = 0;
    ++st_temp.len;
    st_temp.status = STAT_OK;
    return st_temp;
}




struct st_proces_param scan_input_array(char *str)
{

    struct st_proces_param st_temp;
    for(unsigned int i = 0; i < MAX_LEN_COMMAND; ++i){st_temp.array_comand[i] = 0;}
    st_temp.len = 0;
    st_temp.status = STAT_ERROR;

//    int ch;
    unsigned char begin_wd = 0;
    unsigned int count_wd = 0;
    unsigned int count_char = 0;

    while ((*(str + count_char)) != 0)
    {
        if(0 == count_wd)
        {
            if(0 == begin_wd)
            {
                if(' ' != (*(str + count_char)))
                {
                    if(0 == count_wd)
                    {
                        st_temp.array_comand[0] = (*(str + 0));
                        count_char = 1;
                    }

                    begin_wd = 1;
//                    st_temp.status = STAT_OK;
                }
            }
            else
            {

                if(' ' == (*(str + count_char)))
                {
                    begin_wd = 0;
                    ++count_wd;
                    if(MAX_LEN_COMMAND < count_wd)
                    {st_temp.status = STAT_ERROR;return st_temp;}
                }
                else
                {
                    if(0 == count_wd)
                    {
                        st_temp.array_comand[count_char] = (*(str + count_char));
                        ++count_char;
                        if(MAX_LEN_COMMAND <= count_char)
                        {st_temp.status = STAT_ERROR;return st_temp;}
                    }
                }
            }
        }
        else
        {
            (*(str + st_temp.len)) = (*(str + st_temp.len + count_char + 1));
            ++st_temp.len;
            if((MAX_LEN_INPUT_STR - MAX_LEN_COMMAND - 2) < st_temp.len)
            {
                st_temp.len = MAX_LEN_INPUT_STR - MAX_LEN_COMMAND;
                (*(str + MAX_LEN_INPUT_STR - MAX_LEN_COMMAND - 1)) = 0;
                return st_temp;
            }
        }

    }

    (*(str + st_temp.len)) = 0;
    ++st_temp.len;
    st_temp.status = STAT_OK;
    return st_temp;
}



int gluing_strings(char* str_com, char* str_1, char* str_2)
{
    int count_com = 0;

    while(0 != (*(str_1 + count_com)))
    {
        (*(str_com + count_com)) = (*(str_1 + count_com));
        ++count_com;
        if((MAX_LEN_INPUT_STR - 1) == count_com){(*(str_com + count_com)) = 0;return count_com;}
    }
    (*(str_com + count_com)) = ' ';
    ++count_com;

    int count_temp = 0;
    while(0 != (*(str_2 + count_temp)))
    {
        (*(str_com + count_com)) = (*(str_2 + count_temp));
        ++count_com;
        ++count_temp;
        if((MAX_LEN_INPUT_STR - 1) == count_com){(*(str_com + count_com)) = 0; return count_com;}
    }

    (*(str_com + count_com)) = 0;

    return count_com;
}







