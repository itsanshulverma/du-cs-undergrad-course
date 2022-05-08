% File input & output
% see(file1), read(X),
% p(X, Y),         % Compute Y that is in relation p with X
% tell(file2), write(Y), write(.).    % Write full stop after Y


% User Input & Output
cube:-
  write('Next item, please: '),
  read(X),
  process(X).

process(stop):- !.

process(N):-
  C is N * N * N,
  write('Cube of '), write(N), write(' is '), 
  write(C), nl, 
  cube.

% Output

% ?- cube.
% Next item, please: 5.
% Cube of 5 is 125
% Next item, please: |: 12.
% Cube of 12 is 1728
% Next item, please: |: stop.

% true.

% Displaying List
writelist([]).

writelist([X|L]):-
  write(X), nl,
  writelist(L).

% Output

% ?- writelist([[a, b, c], [d, e, f], [g, h, i]]).
% [a,b,c]
% [d,e,f]
% [g,h,i]
% true.

% A list of integer numbers can be shown as a bar graph.
bars([]).
bars([N|L]):-
  stars(N), nl,
  bars(L).

stars(N):-
  N>0,
  write(*),
  N1 is N - 1,
  stars(N1).
stars(N):-
  N =< 0.

% Output
% ?- bars([3, 4, 6, 5]).
% ***
% ****
% ******
% *****
% true .
