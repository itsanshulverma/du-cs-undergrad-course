%% 5.1 - Let a program be:

p(1).
p(2) :- !.
p(3).

%% Write all of Prolog’s answers to the following queries:

% OUTPUT

% 1 ?- p(X).
% X = 1 ;
% X = 2.

% 2 ?- p(X), p(Y).
% X = Y, Y = 1 ;
% X = 1,
% Y = 2 ;
% X = 2,
% Y = 1 ;
% X = Y, Y = 2.

% 3 ?- p(X), !,  p(Y). 
% X = Y, Y = 1 ;
% X = 1,
% Y = 2.
