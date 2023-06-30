// Complete the skeleton below for a program that reads an integer value x and indicates if x is even or odd (i.e., divisible by 2 or not). You need to change the test condition associated with the if instruction. Note that, as in Python, you may use the % (modulo) operator.

#include <iostream>
using namespace std;

int main() {
  int x;         
  cin >> x;     
  if ( x%2==0 ) { 
    cout << x << " is even\n";
  } else {
    cout << x << " is odd\n";
  }
  return 0;
}