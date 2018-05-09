CXX=clang++-5.0
RM=rm -f
CXXFLAGS=-std=c++14

make: main.cpp 
	$(CXX) $(CXXFLAGS) main.cpp *.o -o a.out
	./a.out
	
Board.o: Board.cpp Board.h  TicTacToe.cpp TicTacToe.h Champion.cpp Champion.h DummyPlayers.cpp DummyPlayers.h
	$(CXX) $(CXXFLAGS) -c Board.cpp
	$(CXX) $(CXXFLAGS) -c Champion.cpp
	$(CXX) $(CXXFLAGS) -c TicTacToe.cpp
	$(CXX) $(CXXFLAGS) -c DummyPlayers.cpp

Node.o: Node.cpp Node.h 
	$(CXX) $(CXXFLAGS) -c Node.cpp

clean:
	$(RM) *.o a.out