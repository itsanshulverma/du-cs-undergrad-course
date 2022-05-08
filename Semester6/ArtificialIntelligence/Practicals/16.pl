%  Written by Anshul Verma for University of Delhi
/* 16. Write a prolog program to implement insert_nth(I, N, L, R) that
 inserts an item I into Nth position of list L to generate a list R. */

insert_nth(I, 1, L, [I|L]):- !.
insert_nth(I, N, [H|T], [H|T1]):-
  N1 is N - 1,
  insert_nth(I, N1, T, T1).

/* OUTPUT

?- insert_nth(2, 2, [1,3,4,5], R).          
R = [1, 2, 3, 4, 5].

?- insert_nth(20, 1, [1,3,4,5], R). 
R = [20, 1, 3, 4, 5].

?- insert_nth(20, 5, [23, 535, 55, 34, 56, 778, 67, 97], R). 
R = [23, 535, 55, 34, 20, 56, 778, 67, 97].

?- insert_nth(25, 15, [23, 535, 55, 34, 56, 778, 67, 97], R). 
false.

*/

