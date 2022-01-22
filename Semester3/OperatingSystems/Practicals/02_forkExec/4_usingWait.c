/*
	Anshul Verma, 19/78065
	
	d) before terminating, the parent waits for the child to finish 
its task

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int a;
	a=fork();
	if(a<0)
	{
    	printf("child process could not be created");
    	exit(-1);
  	}
  	else if(a==0)
  	{
  		printf("Child process : My ID is %d\n",getpid());
  	}
  	else
  	{ 
  		wait(NULL);
  		printf("Parent process : My ID is %d\n",getpid());
  	}
  	return 0;
}