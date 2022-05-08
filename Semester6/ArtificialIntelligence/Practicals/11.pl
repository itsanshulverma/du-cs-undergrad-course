%  Written by Anshul Verma for University of Delhi
/* 11. Write a program in PROLOG to implement palindrome(L) 
which checks whether a list L is a palindrome or not. */

conc([], L, L).
conc([X|L1], L2, [X|L3]):-
  conc(L1, L2, L3).

palindrome([]):- !.
palindrome([_]):- !.
palindrome(L):-
  conc([Head|Tail], [Head], L),
  palindrome(Tail), !.

/* OUTPUT

?- palindrome([]).   
true.

?- palindrome([a]).  
true.

?- palindrome([a, b, a]).
true.

?- palindrome([a, b, b]). 
false.

*/

