#pragma once
#include "Board.h"
#include "Player.h"

class TicTacToe{
    public:
    Board game;
    Player win;
    bool ifWin(Player &p);
    public:
    TicTacToe(int size);
    Board board() const;
    Player winner() const;
    void play(Player& xPlayer, Player& oPlayer);

};