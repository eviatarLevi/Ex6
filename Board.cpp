#include "Board.h"



Board::Board(int n) : mat(new Node**[n])
{
    this->n = n;
    for(int i = 0 ; i < n ; i++){
        mat[i] = new Node*[n];
        for(int j = 0 ; j < n ; j++)
            mat[i][j] = new Node('.');
    }
}
Board::Board(const Board &b): mat(new Node**[b.n])
{
    this->n = b.n;
    for(int i = 0 ; i < n ; i++){
        mat[i] = new Node*[n];
        for(int j = 0 ; j < n ; j++)
            mat[i][j] = new Node(b.mat[i][j]->getC());
    }
}
Board::~Board()
{
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)
            delete(mat[i][j]);
        delete(mat[i]);
    }
    
}
Node& Board::operator[](list <int> l)
{
    int a  = l.front(),b = l.back();;
    if(a < n && a >= 0 && b <n && b >= 0)
        return *(this->mat[a][b]);
    else {
        IllegalCoordinateException ex;
        ex.setA(a); ex.setB(b);
        throw ex;
    }//exp
}
void Board::operator=(char c)
{
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)
            mat[i][j]->setC(c);
    }
}
void Board::operator=(const Board &b)
{
    delete(this);
    Board ans = b;
    this->mat = ans.mat;
    this->n = ans.n;
}

