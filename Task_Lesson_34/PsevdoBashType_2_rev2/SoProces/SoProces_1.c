/*
 * main.c
 */
#include "SoProces_1.h"


#define MAX_LEN_WAY 4096


int main(int argc, char* argv[])
{
//	printf("0 = %s\n", argv[0]);
//	printf("1 = %s\n", argv[1]);
//	printf("2 = %s\n", argv[2]);
//	printf("3 = %s\n", argv[3]);

	if(NULL == argv[0]){printf("not define comand\n");exit(EXIT_SUCCESS);}
	if(NULL == argv[1]){printf("not define Param_2\n");exit(EXIT_SUCCESS);}
	if(NULL == argv[2]){printf("not define Param_1\n");exit(EXIT_SUCCESS);}
	if(NULL == argv[3]){printf("not define name pipe write\n");exit(EXIT_SUCCESS);}

	////////////////////////////////////////////////
        int pipe_read_fd_com = open(argv[0], O_RDONLY);    // O_RDONLY
        if(-1 == pipe_read_fd_com){perror("Could not open pipe for reading"); return 0;}
        char temp_str_com[MAX_LEN_WAY];
        if(-1 == read(pipe_read_fd_com, temp_str_com, MAX_LEN_WAY)){perror("could not read to pipe"); return 0;}
	////////////////////////////////////////////////
//printf("5 = %s\n", temp_str_com);
        int pipe_read_fd_par_1 = open(argv[1], O_RDONLY);    // O_RDONLY
        if(-1 == pipe_read_fd_par_1){perror("Could not open pipe for reading"); return 0;}
        char temp_str_par_1[MAX_LEN_WAY];
        if(-1 == read(pipe_read_fd_par_1, temp_str_par_1, MAX_LEN_WAY)){perror("could not read to pipe"); return 0;}
	////////////////////////////////////////////////
//printf("6 = %s\n", temp_str_par_1);
        int pipe_read_fd_par_2 = open(argv[2], O_RDONLY);    // O_RDONLY
        if(-1 == pipe_read_fd_par_2){perror("Could not open pipe for reading"); return 0;}
        char temp_str_par_2[MAX_LEN_WAY];
        if(-1 == read(pipe_read_fd_par_2, temp_str_par_2, MAX_LEN_WAY)){perror("could not read to pipe"); return 0;}
	////////////////////////////////////////////////
//printf("7 = %s\n", temp_str_par_2);

/////////////////////////////////////////////////////////////////////////////////////
	int pipe_write_fd = open(argv[3], O_WRONLY);    // O_WRONLY
	if(-1 == pipe_write_fd){perror("Could not open pipe for writing"); return 0;}
	//if(-1 == write(pipe_write_fd, data_to_execution.array_name, strlen(data_to_execution.array_name))){perror("could not write to pipe"); return 0;}
	//if(-1 == close(pipe_write_fd)){perror("Could not close pipe read end"); return 0;}
/////////////////////////////////////////////////////////////////////////////////////

	if (strcmp ("help", temp_str_par_1)==0)
	{
		char temp_str_write[MAX_LEN_WAY] = "param_1 can be:\n               -'normal' - print string\n               -'revers' - revers print string\n";
		if(-1 == write(pipe_write_fd, temp_str_write, strlen(temp_str_write))){perror("could not write to pipe"); return 0;}
		if(-1 == close(pipe_write_fd)){perror("Could not close pipe read end"); return 0;}
		exit(EXIT_SUCCESS);
	}

	if (strcmp ("normal", temp_str_par_1)==0)
	{
	//    	int len = strlen(temp_str_par_2);
	//    	temp_str_par_2[len] = '\n';
	//    	temp_str_par_2[len + 1] = 0;
		if(-1 == write(pipe_write_fd, temp_str_par_2, MAX_LEN_WAY)){perror("could not write to pipe"); return 0;}
//		if(-1 == write(pipe_write_fd, temp_str_par_2, strlen(temp_str_par_2))){perror("could not write to pipe"); return 0;}
		if(-1 == close(pipe_write_fd)){perror("Could not close pipe read end"); return 0;}
		exit(EXIT_SUCCESS);
	}

	if (strcmp ("revers", temp_str_par_1)==0)
	{
		char temp_str[MAX_LEN_WAY];
		int i = 0;
		int j = 0;
		while(0 != temp_str_par_2[i]){++i;}
		while(0 != i)
		{
		    --i;
		    temp_str[j] = temp_str_par_2[i];
		    ++j;
		}
		temp_str[j] = 0;
		if(-1 == write(pipe_write_fd, temp_str, strlen(temp_str) + 1)){perror("could not write to pipe"); return 0;}
//		if(-1 == write(pipe_write_fd, temp_str, strlen(temp_str))){perror("could not write to pipe"); return 0;}
		if(-1 == close(pipe_write_fd)){perror("Could not close pipe read end"); return 0;}
		exit(EXIT_SUCCESS);
	}


    	char temp_str_write[MAX_LEN_WAY] = "Error Param_1";
	if(-1 == write(pipe_write_fd, temp_str_write, strlen(temp_str_write) + 1)){perror("could not write to pipe"); return 0;}
	if(-1 == close(pipe_write_fd)){perror("Could not close pipe read end"); return 0;}
        exit(EXIT_SUCCESS);


}
