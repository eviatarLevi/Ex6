#include "TicTacToe.h"
#include <string>
TicTacToe::TicTacToe(int size):game(size)
{

}
void TicTacToe::play(Player &xPlayer, Player &oPlayer)
{
    game ='.';
    int count = 0;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    while(count < game.size()*game.size()){
        try{
            Coordinate r = xPlayer.play(game);
            if(game[r]=='.')
                game[r] = xPlayer.getChar();
            else
                {win = &oPlayer; return;}
        }
        catch(const string& msg) {win = &oPlayer; return;}
        if(ifWin(xPlayer)) { win = &xPlayer; return;}
        count++;
      //  cout << count << endl;
        if(count < game.size()*game.size()){
            try{
                Coordinate r = oPlayer.play(game);
                if(game[r]=='.')
                    game[r] = oPlayer.getChar();
                else
                    {win = &xPlayer; return;}
            }
            catch(const string& msg) {win = &xPlayer; return;}

            if(ifWin(oPlayer)) { win = &oPlayer; return;}
            count++;
        }
    }   
    win = &oPlayer;
}
bool TicTacToe::ifWin(Player &p)
{
    bool b = true;
    for(int i = 0; i< game.size() ; i++)
    {
        b = true;
        for(int j = 0; j<game.size() ; j++)
        {
            if(game[{i,j}] != p.getC()){
                b = false;
                break;
            }
        }
        if(b == true) return true;
        b = true;
        for(int j = 0; j<game.size() ; j++)
        {
            if(game[{j,i}] != p.getC()){
                b = false;
                break;
            }
        }
        if(b == true) return true;
    }
    b = true;
    for(int i = 0; i< game.size() ; i++)
    {
        if(game[{i,i}] != p.getC()){
                b = false;
                break;
            }
    }
     if(b == true) return true;
    b = true;
    for(int i = 0; i< game.size() ; i++)
    {
        if(game[{game.size()-i-1,i}] != p.getC()){
                b = false;
                break;
            }
    }
    if(b == true) return true;
    return false;
}
Board TicTacToe::board() const
{
    return game;
}
Player& TicTacToe::winner() const
{
    return *win;
}
