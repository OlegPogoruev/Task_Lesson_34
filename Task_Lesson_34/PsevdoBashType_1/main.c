


#include "main.h"


#include <stdlib.h>

       #include <sys/types.h>
       #include <sys/wait.h>


// feacher funktion fork()
#include <unistd.h>
#include <stdio.h>




#include <malloc.h>
#include <dirent.h>




#define MAX_LEN_WAY 4096
char way_to_dir_proces[MAX_LEN_WAY] = "./SoProces/";
//char way_to_dir_proces[MAX_LEN_WAY] = "./SoProces/SoProces_1.out";

//struct st_save_name_proces save_name_proces;

//void print_proces_name(void);
unsigned char print_proces_name(unsigned char mode, char* str);

void gluing_strings(char* str_com, char* str_1, char* str_2);



struct st_proces_param scan_input_string(void);


int main(){

    struct st_proces_param data_to_execution;

    printf("instruction\n");
    printf("enter\n");
    printf("name_proces pram_1 param_2\n");
    printf("where\n");
    printf("name_proces - executable process name\n");
    printf("pram_1 - what do whith string\n");
    printf("pram_2 - string less 32 char\n");
    printf("param_1 can be 'help'\n");
    printf("\n for example: \n");
    printf("SoProces_1.out help\n");

    printf("\nproces in folder\n");
    print_proces_name(MODE_PRINTF, NULL);
    printf("\n");

    while(1)
    {
        data_to_execution = scan_input_string();

        if(STAT_OK == data_to_execution.status)
        {
            if (strcmp (data_to_execution.array_name, "exit")==0)
            {
                break;
            }
//            printf("%s\n",data_to_execution.array_name);
//            printf("%s\n",data_to_execution.array_param_1);
//            printf("%s\n",data_to_execution.array_param_2);


            pid_t t;

            t=fork();
            if(t==-1){
               printf("Error\n");
               return 1;
            }

            if(!t){

               if(0 == print_proces_name(MODE_COMPARE, data_to_execution.array_name))
               {
                   char temp_path[MAX_LEN_WAY];
                   
                   gluing_strings(temp_path, way_to_dir_proces, data_to_execution.array_name);
                   printf("%s\n", temp_path);
                   execl(temp_path, data_to_execution.array_param_1, data_to_execution.array_param_2, NULL);
               }
               else
               {
                   printf("Can't find proces %s\n", data_to_execution.array_name);
                   exit(EXIT_SUCCESS);
               }

        //       exit(EXIT_SUCCESS);
            }
            else
            {
               wait(NULL);
            }


        }
        else{printf("Error\n");}


    }


    printf("The End\n");
    return 0;
/*
    pid_t t;

    init_proces();





/////////////////////////////////////////////////////////////////
    printf("Num = %d\n", save_name_proces.number_find_proces);
    if(0 != save_name_proces.number_find_proces)
    {
        int temp = save_name_proces.number_find_proces;
        while(temp)
        {
            printf("%s\n", save_name_proces.array_name[temp - 1]);
            --temp;
        }
    }
/////////////////////////////////////////////////////////////////


    t=fork();
    if(t==-1){
       printf("Error\n");
       return 1;
    }
    printf("After %d\n",a);
    if(!t){
       printf("Child %d\n",getpid());
       printf("Parent %d\n",getppid());




//       execl("/home/oleg/XrenovE/Tasks/Task_Lesson_34/Procces/4/SoProces/SoProces_1.out", "ls", "55", NULL);
//       execl(way_to_dir_proces, "ls", "55", NULL);

       char temp_path[MAX_LEN_WAY];
       
       
       gluing_strings(temp_path, way_to_dir_proces, save_name_proces.array_name[save_name_proces.number_find_proces - 1]);
       printf("%s\n", temp_path);
       execl(temp_path, "ls", "55", NULL);


//       exit(EXIT_SUCCESS);
    }else{
       printf("Parent %d\n",getpid());
       printf("Child %d\n",t);

       //int *temp;

       wait(NULL);
    }




    return 0;
*/
}



struct st_proces_param scan_input_string(void)
{

    struct st_proces_param st_temp;
    for(unsigned int i = 0; i < MAX_LEN_NAME; ++i){st_temp.array_name[i] = 0;}
    for(unsigned int i = 0; i < MAX_LEN_PARAM; ++i){st_temp.array_param_1[i] = 0;}
    for(unsigned int i = 0; i < MAX_LEN_PARAM; ++i){st_temp.array_param_2[i] = 0;}
    st_temp.status = STAT_ERROR;

    int ch;
    unsigned char begin_wd = 0;
    unsigned int count_wd = 0;
    unsigned int count_char = 0;
/*
    unsigned int nc = 0;
    char array[17];
    nc = 0;
    (*number) = 0;
*/
    while ((ch = getchar()) != '\n')
    {
        if(0 == begin_wd)
        {
            if(' ' != ch)
            {


                if(2 == count_wd)
                {
                    st_temp.array_param_2[0] = ch;
                    count_char = 1;
                }

                if(1 == count_wd)
                {
                    st_temp.array_param_1[0] = ch;
                    count_char = 1;
                }


                if(0 == count_wd)
                {
                    st_temp.array_name[0] = ch;
                    count_char = 1;
                }





                begin_wd = 1;
                
                st_temp.status = STAT_OK;
//                ++count_wd;
            }
        }
        else
        {

            if(' ' == ch)
            {
                begin_wd = 0;
                ++count_wd;
                if(MAX_NUMBER_PARAM < count_wd)
                {st_temp.status = STAT_ERROR;return st_temp;}
            }
            else
            {

                if(2 == count_wd)
                {
                    st_temp.array_param_2[count_char] = ch;
                    ++count_char;
                    if(MAX_LEN_PARAM <= count_char)
                    {st_temp.status = STAT_ERROR;return st_temp;}
                }

                if(1 == count_wd)
                {
                    st_temp.array_param_1[count_char] = ch;
                    ++count_char;
                    if(MAX_LEN_PARAM <= count_char)
                    {st_temp.status = STAT_ERROR;return st_temp;}
                }


                if(0 == count_wd)
                {
                    st_temp.array_name[count_char] = ch;
                    ++count_char;
                    if(MAX_LEN_NAME <= count_char)
                    {st_temp.status = STAT_ERROR;return st_temp;}
                }
            }


        }
    }

    return st_temp;
}











unsigned char print_proces_name(unsigned char mode, char* str)
{
    unsigned char ret = 1;
    struct dirent **namelist;
    int n;



//    save_name_proces.number_find_proces = 0;

    n = scandir("./SoProces", &namelist, NULL, alphasort);
    if (n == -1) {
        perror("scandir");
//        exit(EXIT_FAILURE);
    }

    while (n--) {
//        printf("%s\n", namelist[n]->d_name);
        int i = 0;
        while(0 != namelist[n]->d_name[i]){++i;}
        if(4 < i)
        {
            if(('t' == namelist[n]->d_name[i - 1]) && ('u' == namelist[n]->d_name[i - 2]) && ('o' == namelist[n]->d_name[i - 3]) && ('.' == namelist[n]->d_name[i - 4]))
            {
                if(mode == 0)
                {
                    printf("%s\n", namelist[n]->d_name);
                }
                else
                {
                    if (strcmp (namelist[n]->d_name, str)==0)
                    {
                        ret = 0;
                    }
//                save_name_proces.array_name[save_name_proces.number_find_proces]
//                strncpy (save_name_proces.array_name[save_name_proces.number_find_proces], namelist[n]->d_name,MAX_LEN_NAME);
//                ++save_name_proces.number_find_proces;
                    
                }
            }
        }
        free(namelist[n]);
    }

//if(0 != save_name_proces.number_find_proces){--save_name_proces.number_find_proces;}

    free(namelist);

    return ret;
}


void gluing_strings(char* str_com, char* str_1, char* str_2)
{
    int count_com = 0;

    while(0 != (*(str_1 + count_com)))
    {
        (*(str_com + count_com)) = (*(str_1 + count_com));
        ++count_com;
        if((MAX_LEN_WAY - 1) == count_com){return;}
    }

    int count_temp = 0;
    while(0 != (*(str_2 + count_temp)))
    {
        (*(str_com + count_com)) = (*(str_2 + count_temp));
        ++count_com;
        ++count_temp;
        if((MAX_LEN_WAY - 1) == count_com){return;}
    }

    (*(str_com + count_com)) = 0;

}






