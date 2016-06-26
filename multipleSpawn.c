#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "morph.h"

int main(int argc, char *argv[])
{	
	int i,location=0,remember[location],num, j, count=0, count2=0,status=0;		
	
	if (argc < 2){
		printf("Please enter at least 1 argument\n");
		return 0;
	}

	else if (argc >11)
	{
		printf("ERROR please enter less than 10 arguments\n");
		exit(0);
	}
	
	for (i=0; i < argc-1; i++){
		pid_t wpid = 0, childpid=fork();
	
		if (childpid ==-1){
		printf("Forking error");
		exit(0);	
		}

		else if (childpid==0){
		Morph(argv[i+1]);

		} else {

		wpid = waitpid(-1, &status, 0); 
		if(WEXITSTATUS(status) != 0){
			remember [location]=argv[i+1];
			location ++;
	    } 
	  }
	}
	printf("Here is the filtered list\n");

	for (count2=0;count2<location;count2++){
		printf("%s is a prime\n",remember[count2+1]);
	}

	return 0;
}

int Morph(char *number) 
{ 
	char *args []={"isPrime",number, NULL};
	execvp("./isPrime",args);
}
