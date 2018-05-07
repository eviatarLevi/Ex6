all:
	g++ -c main.cpp Board.cpp Node.cpp
	g++ -o a main.o Board.o Node.o