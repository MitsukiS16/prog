#include <iostream>
using namespace std;


unsigned long bc(unsigned long n, unsigned long k) {
    int C[n + 1][k + 1];
    unsigned long i, j;

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
 
    return C[n][k];
}


int main() {

cout << bc(5, 0) << '\n';
cout << bc(5, 1) << '\n';
cout << bc(5, 5) << '\n';
cout << bc(5, 2) << '\n';
cout << bc(12, 7) << '\n';
cout << bc(20, 10) << '\n';

    return 0;
}