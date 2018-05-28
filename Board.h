#pragma once
#include "Node.h"
#include <iostream>
#include <list>
#include <exception>
#include <string>
#include <fstream>
#include <math.h>
#include <time.h>
using namespace std;
struct RGB {
  uint8_t red, green, blue;
public:
  RGB() {}
  RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};

class Board
{

  public:
    Node **mat;
    int n;
    Board();
    Board(int n);
    Board(const Board &b);
    ~Board();
    void deleteB(Node **mat);
    //Node &operator[](list<int> l);
    Node &operator[](const Coordinate& cr) const;
    void operator=(char);
    void operator=(const Board &b);
    int size() const;
    friend ostream &operator<<(ostream &out, const Board &b);
    friend istream &operator>>(istream &cin, Board &b);
    string draw(const int pix) const;
    private:
    string getTime () const;
    void grid(RGB* img,int pix)const; 
    void eixs(RGB* img,int pix,int x,int y)const;
    void cir(RGB* img,int pix,int x, int y)const;
    int point(int pix,int x,int y)const;
};


class IllegalCoordinateException : public exception
{
    int a, b;

  public:
    void setA(int row)
    {
        this->a = row;
    }
    void setB(int col)
    {
        this->b = col;
    }
    string theCoordinate() const
    {
        return to_string(a) + "," + to_string(b);
    }
};

class IllegalCharException : public exception
{
    char input;

  public:
    char theChar() const
    {
        return input;
    }
    void setInput(int c) { input = c; }
};