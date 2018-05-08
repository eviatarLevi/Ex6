#include "TicTacToe.h"

TicTacToe::TicTacToe(int size):game(size)
{

}
void TicTacToe::play(Player &xPlayer, Player &oPlayer)
{
    int count = 0;
    while(count < game.size()*game.size()){
        oPlayer.play(game);
        if(ifWin(oPlayer)) { win = oPlayer; return;}
        count++;
        if(count < game.size()*game.size()){
            xPlayer.play(game);
            if(ifWin(xPlayer)) { win = xPlayer; return;}
            count++;
        }
    }   
    win = oPlayer;
}
bool TicTacToe::ifWin(Player &p)
{
    for(int i = 0; i< game.size() ; i++)
    {
        bool b = true;
        for(int j = 0; j<game.size() ; j++)
        {
            if(game[{i,j}] != p.getC()){
                b = false;
                break;
            }
            if(b == true) return true;
        }
        for(int j = 0; j<game.size() ; j++)
        {
            if(game[{j,i}] != p.getC()){
                b = false;
                break;
            }
            if(b == true) return true;
        }
    }
    bool b = true;
    for(int i = 0; i< game.size() ; i++)
    {
        if(game[{i,i}] != p.getC()){
                b = false;
                break;
            }
        if(b == true) return true;
    }
    b = true;
    for(int i = 0; i< game.size() ; i++)
    {
        if(game[{game.size()-i-1,i}] != p.getC()){
                b = false;
                break;
            }
        if(b == true) return true;
    }
}
Board TicTacToe::board() const
{
    return game;
}
Player TicTacToe::winner() const
{
    return win;
}
