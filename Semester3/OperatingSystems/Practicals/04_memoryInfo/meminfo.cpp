/*
	3. Write a program to report behaviour of Linux kernel including information on configured memory, amount of free and used memory. (Memory Information)

	Written by Anshul Verma
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	printf("\nKernel Version:\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\nConfigured Memory:\n");
	system("cat /proc/meminfo | awk 'NR==1{print $2}'");
	printf("\nAmount of Free Memory:\n");
	system("cat /proc/meminfo | awk 'NR==2{print $2}'");
	printf("\nAmount of Used Memory:\n");
	system("cat /proc/meminfo | awk '{if(NR==1) a=$2; if(NR==2) b=$2} END {print a-b}'");
	
	return 0;
}
