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


void Node::operator=(char c)
{
    this->setC(c);
}

int Node::operator==(char y) const
{
    int x=this->getC()==y;
    return x;
}