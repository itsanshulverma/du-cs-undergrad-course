%  Written by Anshul Verma for University of Delhi
/* 7. Prolog program to implement multi(N1, N2, R) : where N1 and N2 
denotes the numbers to be multiplied and R represents the result. */

multi(N1, N2, R):-
	R is N1 * N2.

/* OUTPUT

?- multi(11, 22, R).  
R = 242.

?- multi(7, 15, R).  
R = 105.

?- multi(7, 0, R).  
R = 0.

?- multi(8, -21, R). 
R = -168.

*/