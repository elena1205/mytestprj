-module(first).
-export([hello/0]).

hello() -> 
	io:format("hello world~n").
	