all:
	clang++ -std=c++14 -I/usr/local/include/cppconn main.cpp -lmysqlcppconn
run: all
	./a.out < input
