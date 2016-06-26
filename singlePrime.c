#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "morph.h"

//int singlePrime(char *number, char *argv[]);
int main(int argc, char *argv[])
{	
	int i,j;

	if (argc < 2){
		printf("Please enter at least 1 argument\n");
		exit(0);
		return 0;
	}

	else if (!atoi(argv[1])){
		printf("Please insert a digit\n");
		exit(0);
	}

	int count, count2=0,status=0;	
	printf("Before forking..\n");

	pid_t wpid = 0, childpid=fork();
	if (childpid ==-1){
		printf("Forking error");
		exit(0);	
	}

	else if (childpid==0){
		printf("This is a child process\n");
		Morph(argv[1]);

		} else {
		printf("This is a parent process\n");	
		}
		
	wpid = waitpid(-1, &status, 0); 

	if(WEXITSTATUS(status) != 0)
		printf("PRIME!\n");
	
	else 
		printf("Not a prime\n");
}

int Morph(char *number) 
{ 
	char *args []={"isPrime",number, NULL};
	execvp("./isPrime",args);
}
