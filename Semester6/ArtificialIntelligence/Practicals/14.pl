%  Written by Anshul Verma for University of Delhi
/* 14. Write a Prolog program to implement nth_element(N, L, X) 
where N is the desired position, L is a list and 
X represents the Nth element of L. */

nth_element(1, [H|_], H):- !.
nth_element(N, [_|T], X):-
	N > 0,
	N1 is N - 1,
	nth_element(N1, T, X).

/* OUTPUT

?- nth_element(1, [a, b, c, d, e, f], X).
X = a.

61 ?- nth_element(2, [a, b, c, d, e, f], X). 
X = b.

62 ?- nth_element(3, [a, b, c, d, e, f], X).
X = c.

63 ?- nth_element(4, [a, b, c, d, e, f], X). 
X = d.

*/

