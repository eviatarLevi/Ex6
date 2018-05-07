#include <iostream>
using namespace std;

class Node
{
private:
  char c;

public:
  Node();
  Node(char c);
  void setC(char c);
  char getC() ;
  void operator=(char c);
  friend ostream &operator<<(ostream &out, Node &b);
  int operator==(char y);
};

inline ostream &operator<<(ostream &out, Node &b)
{
    out<<b.getC();
    return out;
}


