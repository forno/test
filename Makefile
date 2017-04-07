all:
	clang++ -std=c++14 main.cpp
run: all
	./a.out < input
