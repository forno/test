all: main.cpp
	clang++ -std=c++14 -lboost_system main.cpp
run: all
	./a.out < input
