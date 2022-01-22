/* A C-program to demonstrate use of sizeof operator */
#include<stdio.h>
int main() {
	
    int intType = 0;
    float floatType = 1.0 + 20.00;
    double doubleType = 1.23;
    char charType = 'a';

    // sizeof evaluates the size of a variable
    printf("Size of int: %zu bytes\n", sizeof(intType));
    printf("Size of float: %zu bytes\n", sizeof(floatType));
    printf("Size of double: %zu bytes\n", sizeof(doubleType));
    printf("Size of char: %zu byte\n", sizeof(charType));
    
    return 0;
}