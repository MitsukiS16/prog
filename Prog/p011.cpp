/*

Write a C++ program that “plays” a version of the known game FizzBuzz over a sequence of natural numbers up to an integer n provided by the user.

The program should build and finally print a string with each number in the sequence separated by a space. However:

If the number is a multiple of 3, appends the word "Fizz" instead
If the number is a multiple of 5, appends the word "Buzz" instead
If the number is both a multiple of 3 and 5, nothing is 

*/

#include <iostream>
using namespace std;

int main() {
    int n = 0;

    cin >> n;

    for(int i=1; i<=n; i++) {
        if(i%3==0 && i%5==0) continue;
        else if(i%3==0) cout << "Fizz ";
        else if(i%5==0) cout << "Buzz ";
        else cout << i << " ";
    }

    return 0;
}
