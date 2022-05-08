%  Written by Anshul Verma for University of Delhi
/* 9. Write a Prolog program to implement conc (L1, L2, L3) where L2 
is the list to be appended with L1 to get the resulted list L3. */

conc([], L, L).
conc([X | L1], L2, [X | L3]):-
  conc(L1, L2, L3).

/* OUTPUT

?- conc([a, b, c], [1, 2, 3], L).
L = [a, b, c, 1, 2, 3].

?- conc([a, [b, c], d], [a, [], b], L). 
L = [a, [b, c], d, a, [], b].

?- conc(L1, L2, [a, b, c]).                     
L1 = [],
L2 = [a, b, c] ;
L1 = [a],
L2 = [b, c] ;
L1 = [a, b],
L2 = [c] ;
L1 = [a, b, c],
L2 = [] ;
false.

?- conc(Before, [may | After], 
  [jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec]).
Before = [jan, feb, mar, apr],
After = [jun, jul, aug, sep, oct, nov, dec] ;
false.

?- conc(_, [Month1, may, Month2 | _], 
  [jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec]).     
Month1 = apr,
Month2 = jun ;
false.

?- L1 = [a, b, z, z, c, z, z, z, d, e],     % A given list
  conc(L2, [z, z, z | _], L1).              % L2 is L1 upto 3 z's
L1 = [a, b, z, z, c, z, z, z, d|...],
L2 = [a, b, z, z, c] ;
false.

*/

