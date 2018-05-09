CXX=clang++-5.0
RM=rm -f
CXXFLAGS=-std=c++14

all: Board.o Node.o

make: all main.o
	$(CXX) $(CXXFLAGS) *.o
	./a.out
	
Board.o: Board.cpp Board.h  TicTacToe.cpp TicTacToe.h Champion.cpp Champion.h DummyPlayers.cpp DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c Board.cpp
	$(CXX) $(CXXFLAGS) -c Champion.cpp
	$(CXX) $(CXXFLAGS) -c TicTacToe.cpp
	$(CXX) $(CXXFLAGS) -c DummyPlayers.cpp

make.o: make.cpp TicTacToe.h Champion.h DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c make.cpp

Node.o: Node.cpp Node.h
	$(CXX) $(CXXFLAGS) -c Node.cpp

clean:
	$(RM) *.o a.out
