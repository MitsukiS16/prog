#include <iostream>
using namespace std;

int main() {
    int number;
    int reverse = 0;
    int resto = 0;

    cin >> number;


    while(number!=0) {
        resto = number % 10;
        reverse = (reverse + resto);
        number = (number - resto) / 10;
        if(number!=0) reverse *= 10;
    }
    cout << reverse << endl;

    return 0;
}

