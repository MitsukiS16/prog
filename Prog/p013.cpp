#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
    
    int k = 0;
    int d = 0;
    double sum = 0;

    cin >> k;
    cin >> d;

    for(int i=0; i<=k; i++) {
        double increment = pow(-1, i) / (2*i+1);
        sum += increment;
    }
    sum *= 4;

    cout << fixed << setprecision(d) << sum << std::endl;



    return 0;
}