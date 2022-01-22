/*
	2. Write a program to report behaviour of Linux kernel including kernel version, CPU type and model. (CPU Information)

	Written by Anshul Verma
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	
	printf("\nKernel Version:\n");
	system("cat /proc/sys/kernel/osrelease");
	printf("\n-- CPU ----\n");
	system("cat /proc/cpuinfo | awk 'NR==3{print}'");
	system("cat /proc/cpuinfo | awk 'NR==4{print}'");
	system("cat /proc/cpuinfo | awk 'NR==5{print}'");
	printf("\n");
	
	return 0;
}
