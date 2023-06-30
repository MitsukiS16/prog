#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

void add(const complex& a, const complex& b, complex& r){
    r.x=a.x+b.x;
    r.y=a.y+b.y;
}

void mul(const complex& a, const complex& b, complex& r){
    r.x=a.x*b.x-a.y*b.y;
    r.y=a.x*b.y+a.y*b.x;
}

void mandelbrot(const complex& c, unsigned int n, complex& z_n){
    z_n = {0,0};
    complex c1 = {0,0};
    complex c2 = {0,0};

    for (unsigned int i = 0; i < n; i++) {
        mul(z_n,z_n, c1);
        add(c1, c, c2);
        z_n=c2;
    }

}

int main(){
    return 0;
}