%  Written by Anshul Verma for University of Delhi
/* 4. Write a program in PROLOG to implement generate fib(N,T) where 
T represents the Nth term of the fibonacci series. */

fib(1, 0):- !.
fib(2, 1):- !.
fib(N, T):-
	N > 2,
	N1 is N - 1,
	N2 is N1 - 1, 
	fib(N1, T1),
	fib(N2, T2),
	T is T1 + T2.

/* OUTPUT

?- fib(1, T).
T = 0.

?- fib(2, T).
T = 1.

?- fib(3, T).
T = 1.

?- fib(4, T).        
T = 2.

?- fib(5, T).
T = 3.

?- fib(10, T). 
T = 34.

?- fib(-1, T). 
false.

*/