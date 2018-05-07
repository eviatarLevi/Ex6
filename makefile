make: main.cpp Board.o Node.o
	clang++-5.0 -std=c++17 main.cpp *.o -o a.out
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp Board.h 
	clang++-5.0 -std=c++17 -c Board.cpp -o Board.o

Node.o: Node.cpp Node.h 
	clang++-5.0 -std=c++17 -c Node.cpp -o Node.o

clean:
	rm *.o a.out