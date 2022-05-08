%  Written by Anshul Verma for University of Delhi
/* 5. Write a Prolog program to implement GCD of two numbers. */

gcd(0, A, A):- !.
gcd(A, 0, A):- !.
gcd(A, B, C):-
	B1 is mod(A, B),
	gcd(B, B1, C).

/* OUTPUT

?- gcd(15, 25, C). 
C = 5.

?- gcd(0, 25, C).  
C = 25.

?- gcd(12, 0, C). 
C = 12.

?- gcd(12, 13, C). 
C = 1.

*/