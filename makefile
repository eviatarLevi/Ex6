make: main.cpp Board.o Node.o
	clang++-5.0 -std=c++17 main.cpp *.o -o a.out
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp Node.cpp Board.h Node.h
	clang++-5.0 -std=c++17 -c Board.cpp Node.cpp 

clean:
	rm *.o a.out