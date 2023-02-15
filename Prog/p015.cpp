#include <iostream>
using namespace std;


bool isPrime(int n) {
    if(n==0 || n==1) return false;
    for(int i=2; i<n/2+1; i++) {
        if(n%i==0) return false;
    }
    return true;
}



bool isPernicious(int n) {
    int cntNumberOne = 0;

    while(n!=0) {
        if(n%2!=0) cntNumberOne++;
        n/=2;
    }
    return isPrime(cntNumberOne);
}



int main() {
    int nInicial = 0;
    int nFinal = 0;
    
    cin >> nInicial;
    cin >> nFinal;

    for(int i=nInicial; i<=nFinal; i++) {
        if(isPrime(i) && isPernicious(i)) cout << i << " ";
    }
    
    return 0;
}


