#include <iostream>
using namespace std;

int main() {
    
    int nF = 0;
    cin >> nF;

    for (int i=2; i<=nF; i++) {
        int j;
        for(j=2; j<=i/2; j++) {
            if(i%j==0) break;
        }
        if(j-1==i/2) cout << i << " ";
    }

    return 0;
}


