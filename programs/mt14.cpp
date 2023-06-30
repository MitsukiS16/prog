#include <iostream>
#include "complex.h"

using namespace std;

complex add(const complex a, const complex b){
    complex r;
    r.real=a.real+b.real;
    r.img=a.img+b.img;
    return r;
}
complex mul(const complex a, const complex b){
    complex r;
    r.real=(a.real*b.real)-(a.img*b.img);
    r.img=(a.real*b.img) + (b.real*a.img);
    return r;
}

void mandel(complex c, int n, complex z[]) {
    z[0] = {0, 0};
    for(int i=1; i<n; i++) {
        z[i] = add(mul(z[i-1],z[i-1]),c);
    }
}

int main() {
{ complex c = { 0, 0 };
  const int n = 1;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
{ complex c = { 0, 0 };
  const int n = 3;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
{ complex c = { 1, 1 };
  const int n = 3;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
{ complex c = { -1, 0 };
  const int n = 6;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
{ complex c = { 0, 3 };
  const int n = 5;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }
  
    return 0;
}