%  Written by Anshul Verma for University of Delhi
/* 13. Write a Prolog program to implement two predicates
evenlength(List) and oddlength(List) so that they are true 
if their argument is a list of even or odd length respectively. */

evenlength([]):- !.
evenlength([_|T]):- oddlength(T).

oddlength([_]):- !.
oddlength([_|T]):- evenlength(T).

/* OUTPUT

?- evenlength([]).   
true.

?- evenlength([1]). 
false.

?- oddlength([1]).   
true.

?- oddlength([]).   
false.

?- oddlength([1, 2, 3, 4]). 
false.

?- evenlength([1, 2, 3, 4]). 
true.

*/

