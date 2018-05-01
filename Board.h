#pragma once
#include "Node.h"
#include <iostream>
#include <list>
#include <exception>
#include <string>
using namespace std;

class Board 
{
    public:
    Node*** mat;
    int n;
    public:
    Board(int n);
    Board(const Board &b);
    ~Board();
    Node& operator[] (list<int> l);
    void operator=(char);
    void deleteNode(Node*** t);
    void operator=(const Board &b);
    friend ostream& operator << (ostream& out,const Board &b);
};
inline ostream& operator << (ostream& out,const Board &b){
      for(int i = 0 ; i < b.n ; i++){
        for(int j = 0 ; j < b.n ; j++)
            cout << b.mat[i][j]->getC();
        cout << endl;
    }
    return out;
}
class IllegalCoordinateException : public exception
{
    int a,b;
    public: 
        void setA(int row){
            this->a=row;
            }
        void setB(int col){
            this->b=col;
            }
        string theCoordinate() const
        {
            return to_string(a)+","+to_string(b);
        }
};

class IllegalCharException : public exception
{
    char input;
    public:
        char theChar()const 
        {
            return input;
        }
        void setInput(int c){input=c;}
};