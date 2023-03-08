#include "print_array.h"
#include <iostream>
using namespace std;



void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, h = 0;
    while (i<na && j<nb)
    {
        if (a[i] < b[j])
            c[h++] = a[i++];
        else
            c[h++] = b[j++];
    }

    while (i < na)
        c[h++] = a[i++];
  

    while (j < nb)
        c[h++] = b[j++];


} 






int main() {

{ const int NA = 3, NB = 2;
  int a[NA] = { 2, 3, 4 };
  int b[NB] = { 0, 1 };
  int c[NA+NB];
  merge_arrays(a, NA, b, NB, c);
  print_array(c, NA+NB); }

    return 0;
}