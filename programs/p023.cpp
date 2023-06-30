#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int solve_eq(int a, int b, int c, double& x1, double& x2) {
    double delta = pow(b,2.0) - 4.0*a*c;
    int count;


    if(delta < 0) {
        x1 = NAN;
        x2 = NAN;
        count=0;
    } else if( delta == 0) {
        x1 = (-b)/(2.0*a);
        x2 = NAN;
        count=1;

    } else {
        x1 = (-b-sqrt(delta))/(2.0*a);
        x2 = (-b+sqrt(delta))/(2.0*a); 
        count=2;
    }

    return count;
}


int main() {
double x1, x2; 
int r = solve_eq(3, 4, -2, x1, x2); 
cout << fixed << setprecision(7) 
     << r << ' ' << x1 << ' ' << x2 << '\n'; 

    return 0;
}