#include "Board.h"

Node::Node()
{
}

Node::Node(char c)
{
    this->setC(c);
}
void Node::setC(char c)
{
    if (c == '.' || c == 'X' || c == 'O')
        this->c = c;
    else
    {
        IllegalCharException ex;
        ex.setInput(c);
        throw ex;
    }
}
char Node::getC() const
{
    return this->c;
}


Node& Node::operator=(char c)
{
    this->setC(c);
    return *this;
}

Coordinate::Coordinate(int xVal, int yVal):x(xVal),y(yVal)
{

}
void Coordinate::setXY(int xVal, int yVal) 
{
    x = xVal;
    y = yVal;
}
