make: main.cpp Board.o Node.o
	g++ main.cpp *.o -o a.out -std=c++11
	valgrind --tool=memcheck ./a.out

Board.o: Board.cpp Node.cpp
	g++ -c Board.cpp Node.cpp -std=c++11

clean:
	rm *.o a.out