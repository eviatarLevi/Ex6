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

Node &Node::operator=(char c)
{
    if (c == 'X' || c == 'O' || c == '.')
    {
        this->c = c;
        return *this;
    }
    else
    {
        IllegalCharException ex;
        ex.setInput(c);
        throw ex;
    }
    return *this;
}
Node::operator char() const
{
    return this->getC();
}