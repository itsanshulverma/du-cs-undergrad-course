%  Written by Anshul Verma for University of Delhi
/* 1. Write a prolog program to calculate the sum of two numbers. */

sum(A, B, C):- 
	C is A + B.

/* OUTPUT

?- sum(4, 5, S).
S = 9.

?- sum(38, 29, X). 
X = 67.

*/