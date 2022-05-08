%  Written by Anshul Verma for University of Delhi
/* 8. Write a Prolog program to implement memb(X, L): to check 
whether X is a member of L or not. */

memb(X, [X | Tail]).
memb(X, [Head | Tail]):-
  memb(X, Tail).

/* OUTPUT

?- memb(b, [a, b, c]). 
true .

?- memb(X, [a, b, c]).
X = a ;
X = b ;
X = c ;
false.

?- memb(a, L), memb(b, L), memb(c, L).
L = [a, b, c|_] ;
L = [a, b, _, c|_] ;
L = [a, b, _, _, c|_] ;
...

?- L = [_, _, _],
   memb(a, L), memb(b, L), memb(c, L). 
L = [a, b, c] ;
L = [a, c, b] ;
L = [b, a, c] ;
L = [c, a, b] ;
L = [b, c, a] ;
L = [c, b, a] ;
false.

?- memb(apple, L).
L = [apple|_] ;         % Any list that has “apple” as the head
L = [_, apple|_] ;      % First item is anything, second is “apple”
L = [_, _, apple|_] ;
L = [_, _, _, apple|_] ;
...

*/

