%% 5.2 - The following relation classifies numbers into three classes: 
%% positive, zero and negative:

% class(Number, positive) :- Number > 0.
% class(0, zero).
% class(Number, negative) :- Number < 0.

%% Define this procedure in a more efficient way using cuts.

%% Output

% 1 ?- class(2, X).
% X = positive ;
% false.

% 2 ?- class(-5, X).
% X = negative.

% 3 ?- class(0, X).
% X = zero ;
% false.

% SOLUTION

class(Number, positive) :- Number > 0, !.
class(0, zero) :- !.
class(Number, negative) :- Number < 0.

% Output

% 1 ?- class(2, X).       
% X = positive.

% 2 ?- class(0, X).       
% X = zero.

% 3 ?- class(-5, X).
% X = negative.
