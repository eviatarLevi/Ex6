#include "Board.h"

Board::Board()
{

}

Board::Board(int n) : mat(new Node *[n])
{
    this->n = n;
    for (int i = 0; i < n; i++)
    {
        this->mat[i] = new Node[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = Node('.');
    }
}
Board::Board(const Board &b) : mat(new Node *[b.n])
{
    this->n = b.n;
    for (int i = 0; i < n; i++)
    {
        this->mat[i] = new Node[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = b.mat[i][j];
    }
}
void Board::deleteB(Node **mat)
{
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;
}
Board::~Board()
{
    deleteB(mat);
}
/*Node &Board::operator[](list<int> l)
{
    int a = l.front(), b = l.back();
    
    if (a < n && a >= 0 && b < n && b >= 0)
        return mat[a][b];
    else
    {
        IllegalCoordinateException ex;
        ex.setA(a);
        ex.setB(b);
        throw ex;
    } 
}*/
Node &Board::operator[](const Coordinate& cr) const{
  int a = cr.getX(), b = cr.getY();
    
    if (a < n && a >= 0 && b < n && b >= 0)
        return mat[a][b];
    else
    {
        IllegalCoordinateException ex;
        ex.setA(a);
        ex.setB(b);
        throw ex;
    } 
}
void Board::operator=(char c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j].setC(c);
    }
}

void Board::operator=(const Board &b)
{
    if (this == &b)
        return;
    if (b.n != this->n)
    {
        deleteB(mat);
        this->n = b.n;
        mat = new Node *[b.n];
        for (int i = 0; i < n; i++)
        {
            this->mat[i] = new Node[n];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            mat[i][j] = b.mat[i][j];
    }
}

ostream &operator<<(ostream &out, const Board &b)
{
    for (int i = 0; i < b.n; i++)
    {
        for (int j = 0; j < b.n; j++)
            out << b.mat[i][j].getC();
        out << endl;
    }
    return out;
}
int Board::size() const
{
    return n;
}
