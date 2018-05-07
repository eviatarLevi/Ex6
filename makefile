all:
	g++ -c main.cpp Board.cpp Node.cpp
	g++ -o prog main.o Board.o Node.o