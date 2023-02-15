// Complete the skeleton below for a program that reads an integer value x and writes the value of x and x2−x+1. As in Python, you may use operators *, + and - for multiplication, addition and subtraction, respectively. Unlike in Python, however, the power operator (**) does not exist in C++.

#include <iostream>
using namespace std;

int main() {
  int x; 
  cin >> x; 
  int y = (x*x)-x+1;
  cout << x << ' ' << y << '\n'; 
  return 0;
}


