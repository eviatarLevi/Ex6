#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
    

    for (int x=0; x<board.size(); ++x) {
        Coordinate c{board.size()-1-x,x};
        if(x==1 && board[{0,board.size()-1}] == '.')
            c.setXY(0,board.size()-1);
		if(board[c]=='.') {
			return c;
        }
		
	}
	return {0,0};

}
