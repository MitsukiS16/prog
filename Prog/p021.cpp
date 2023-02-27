#include <iostream>
using namespace std;

int adigits(int a, int b, int c) {
    int number = (max(a,max(b,c))) *10;
    number += (a+b+c)-(max(a,max(b,c))) -(min(a,min(b,c))) ;
    number *= 10;
    number += (min(a,min(b,c))) ;
    return number;
}

/*
int main() {

    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';

    return 0;
}
*/