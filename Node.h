#include <iostream>
using namespace std;


class Node
{
    private:
    char c;
    public:
    Node(char c);
    void setC(char c);
    char getC();
    void operator= (char c);
 };
