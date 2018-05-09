#pragma once
#include <string>
#include "Board.h"

class Player{
    private:
    
    

    public:
    char myChar;
    char getC(){return myChar;}
    char getChar(){return myChar;}
    void setChar(char c){myChar = c;}
   // virtual ~Player();
    virtual const string name() const=0;
    virtual const Coordinate play(const Board& board)=0;
};