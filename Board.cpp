#include "Board.h"
using namespace std;
Board::Board(): mat(new Node *[1])
{
    this->n = 1;
    for (int i = 0; i < n; i++)
    {
        this->mat[i] = new Node[n];
        for (int j = 0; j < n; j++)
            mat[i][j] = Node('.');
    }
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
istream &operator>>(istream &cin, Board &board)
{
    string str;
    cin >> str;
    Board b(str.length());
    int j = 0;
    while(j < b.n )
    {
        for(int i = 0 ; i<b.n ; i++)
        {          
            const char* c = str.c_str();
            b.mat[j][i].setC(c[i]);
        }
        j++;
        cin >> str;
    }
    board = b;
    return cin;

}
int Board::size() const
{
    return n;
}
string Board::getTime()const
{
    time_t timeObj;
    time(&timeObj);
    tm *pTime = gmtime(&timeObj);
    char buffer[100];
    sprintf(buffer, "%d%d%d", pTime->tm_hour, pTime->tm_min, pTime->tm_sec);
    return buffer;
}
string Board::draw(const int pix) const
{
    string fileName = getTime() + ".ppm";
    ofstream imageFile(fileName, ios::out | ios::binary);
    imageFile << "P6" << endl << pix <<" " << pix << endl << 255 << endl;
    int pixs = pix*pix;
    RGB * image = new RGB[pixs];
    grid(image,pix);
    for(int i=0; i<n; i++)
    {
       for(int j=0; j<n; j++)
       {
           if(mat[i][j].getC() == 'X') eixs(image,pix,i,j);
           if(mat[i][j].getC() == 'O') cir(image,pix,i,j);
       }
    }

    imageFile.write(reinterpret_cast<char*>(image), 3*pix*pix);
    imageFile.close();
    delete[] image;
    return fileName;
}
void Board::grid(RGB* img,int pix)const
{
    int q = pix/n;
   for(int i=1; i<n; i++)
   {
       for(int j=0; j<pix; j++)
       {
           img[pix*q*i+j].red = 255;
           img[q*i+j*pix].red = 255;
           
       }
   }
}
void Board::eixs(RGB* img,int pix,int x,int y)const
{
    int q = pix/n;
    for(int i=1; i<q; i++)
    {
        img[pix*q*x+pix*i+y*q+i].blue = 255;
        img[(pix*q*x+pix*i+q)+y*q-i].blue = 255;
    }
}

void Board::cir(RGB* img,int pix,int x,int y)const
{
    int q = pix/n;
    int p = pix*q*x+y*q;
    int m = p+pix*(q/2)+(q/2);
    int r = q/2;
    int xs = x*q, ys = y*q;
    int xm = xs + q/2, ym = ys + q/2;
    for(int i=xs; i<((x+1)*q) ; i++)
    {
        for(int j=ys; j<((y+1)*q); j++)
        {
            if(abs((i-xm)*(i-xm)+(j-ym)*(j-ym)-r*r) <= (q/r)*(q/r)*(q/r)*(q/r)*(q/r)*(q/r))
                img[point(pix,i,j)].green = 255;
        }
    }
}
int Board::point(int pix,int x,int y)const
{
    return pix*x+y;
}
