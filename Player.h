#pragma once
#include <string>
#include "Board.h"

class Player{
    private:
    
    

    public:
    char myChar;
    char getC(){return myChar;}
    char getChar(){return myChar;}
   // virtual ~Player();
    virtual const string name() const;
    virtual const Coordinate play(const Board& board);
};