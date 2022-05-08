%  Written by Anshul Verma for University of Delhi
/* 18. Write a program in PROLOG to implement merge(L1, L2, L3)
where L1 is first ordered list and L2 is second ordered list 
and L3 represents the merged list. */

merge([H1|T1], [H2|T2], [H1|T]):-
  H1 < H2, !,
  merge(T1, [H2|T2], T).
merge([H1|T1], [H2|T2], [H2|T]):-
  merge([H1|T1], T2, T), !.
merge(L1, [], L1):- !.
merge([], L2, L2).

/* OUTPUT

?- merge([1, 3, 5, 7], [2, 4, 6, 8], L).    
L = [1, 2, 3, 4, 5, 6, 7, 8].

?- merge([1, 3, 5, 6, 8], [2, 4, 6, 7], L).
L = [1, 2, 3, 4, 5, 6, 6, 7, 8].

*/

