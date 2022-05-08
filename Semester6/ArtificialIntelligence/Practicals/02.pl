%  Written by Anshul Verma for University of Delhi
/* 2. Write a Prolog program to implement max(X, Y, M) so that M is the 
maximum of two numbers X and Y. */

max(X, Y, M):- X > Y, M is X, !.
max(X, Y, M):- Y >= X, M is Y.

/* OUTPUT

?- max(5, 2, M).     
M = 5.

?- max(5, 18, M). 
M = 18.

?- max(-37, -19, M). 
M = -19.

*/