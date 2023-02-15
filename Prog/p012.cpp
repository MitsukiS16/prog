/*
Write a C++ program that reads an integer number n by user input followed by n characters, all separated by spaces, and then prints the number of characters read that are letters, the number of characters read that are digits, and the number of characters read that are not letters or digits.
*/

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    char c = ' ';

    int nNumb = 0;
    int nChar = 0;
    int nOther = 0;

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> c;
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) nChar++;
        else if(c >= '0' && c <= '9') nNumb++;
        else nOther++;
    }
    
    cout << nChar << " ";
    cout << nNumb << " ";
    cout << nOther;

    return 0;
}
