make: main.cpp Board.o Node.o
	clang++-5.0 main.cpp *.o -o a.out -std=c++11
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp Node.cpp Board.h Node.h
	clang++-5.0 -c Board.cpp Node.cpp -std=c++11

clean:
	rm *.o a.out