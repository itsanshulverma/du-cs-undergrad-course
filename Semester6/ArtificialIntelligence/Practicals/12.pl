%  Written by Anshul Verma for University of Delhi
/* 12. Write a Prolog program to implement sumlist(L, S) 
so that S is the sum of a given list L. */

sumList([], 0).
sumList([Head|Tail], S):-
  sumList(Tail, X),
  S is Head + X.

/* OUTPUT

?- sumList([1], S).
S = 1.

?- sumList([1, 2, 3], S).
S = 6.

?- sumList([], S).        
S = 0.

*/

