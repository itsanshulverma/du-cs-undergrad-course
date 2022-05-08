%  Written by Anshul Verma for University of Delhi
/* 3. Write a program in PROLOG to implement factorial(N, F) where F 
represents the factorial of a number N. */

factorial(0, 1):- !.
factorial(N, F):-
	N > 0,
	N1 is N - 1,
	factorial(N1, F1),
	F is N * F1.

/* OUTPUT

?- factorial(1, F).  
F = 1.

?- factorial(5, F).  
F = 120.

?- factorial(-5, F). 
false.

?- factorial(10, F). 
F = 3628800.

*/