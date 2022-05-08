%  Written by Anshul Verma for University of Delhi
/* 17. Write a Prolog program to implement delete_nth(N, L, R) 
that removes the element  on Nth position from a list L 
to generate a list R. */

delete_nth(1, [H|T], T):- !.
delete_nth(N, [H|T], [H|T1]):-
  N1 is N - 1,
  delete_nth(N1, T, T1).

/* OUTPUT

?- delete_nth(2, [1, 2, 3, 4, 5], R).
R = [1, 3, 4, 5].

?- delete_nth(1, [20, 1, 3, 4, 5], R). 
R = [1, 3, 4, 5].

?- delete_nth(5, [23, 535, 55, 34, 20, 56, 778, 67, 97], R). 
R = [23, 535, 55, 34, 56, 778, 67, 97].

?- delete_nth(15, [23, 535, 55, 34, 20, 56, 778, 67, 97], R). 
false.

*/

