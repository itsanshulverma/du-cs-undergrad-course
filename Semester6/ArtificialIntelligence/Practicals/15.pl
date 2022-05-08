%  Written by Anshul Verma for University of Delhi
/* 15. Write a Prolog program to implement maxlist(L, M) so that 
M is the maximum number in the list. */

max(X, Y, M):- X > Y, M is X, !.
max(X, Y, M):- Y >= X, M is Y.

maxlist([H], H):- !.
maxlist([H|T], M):-
	maxlist(T, M1),
	max(H, M1, M).

/* OUTPUT

?- maxlist([1, 2, 3, 4, 5], M).
M = 5.

?- maxlist([1], M).             
M = 1.

?- maxlist([], M).  
false.

?- maxlist([62, 37, 13, 37, 23, 82, 28], M).  
M = 82.

*/

