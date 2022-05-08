%  Written by Anshul Verma for University of Delhi
/* 6. Write a Prolog program to implement power(Num,Pow, Ans) : 
where Num is raised to the power Pow to get Ans. */

power(X, 0, 1):- !.
power(Num, Pow, Ans):-
	Ans is Num^Pow.

/* OUTPUT

?- power(10, 3, Ans). 
Ans = 1000.

?- power(5, 6, Ans).  
Ans = 15625.

?- power(11, 0, Ans). 
Ans = 1.

?- power(11, -3, Ans). 
Ans = 0.0007513148009015778.

*/