#include <iostream>
using namespace std;

int max(const int a[], int n) {
    int max = a[0];

    if(n<1) return -1;
    if(n==1) return a[0];

    else {
        for(int i=0;i<n;i++) {
            if(a[i]>=max) {
                max=a[i];
            }
        }
    }
    return max;
}

int main() {
  { const int n = 1;
  const int a[n] = { -123 };
  cout << max(a,n) << '\n'; }
  { const int n = 3; 
  const int a[n] = { -3, -2, -1 };
  cout << max(a, n) << '\n'; }
  { const int n = 4; 
  const int a[n] = { 4, -2, 3, 1 };
  cout << max(a, n) << '\n'; }
  { const int n = 9;
  const int a[n] = { 10, 20, 30, -2, 50, 3, 1, 50, 49 };
  cout << max(a, n) << '\n'; }
    return 0;
}