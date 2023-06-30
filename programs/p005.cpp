
// Write a program that reads an integer n and prints all numbers d between 1 and n−1 such that d is a divisor of n (e.g. 1, 2, and 5 if n is 10). Hint: you need to use a for loop (as in exercise 4) and an if instruction (as in exercise 3) in the loop body.

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=1; i<n-1; i++) {
       if(n%i == 0) cout << i << ' ';
    }
}