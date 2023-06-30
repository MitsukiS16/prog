#include <iostream>
#include "fraction.h"

using namespace std;

int gcd(int a, int b){
    if (b==0) return a;
    return abs(gcd(b, a%b));

}

int mmc(int a, int b){
    int res;
    res = (a*b)/gcd(a,b);
    return abs(res);

}

fraction add (fraction a, fraction b){
    fraction res;
    res.den = mmc(a.den,b.den);
    res.num = (res.den/a.den)*a.num + (res.den/b.den)*b.num;
    int aux = gcd(res.den,res.num);
    res.den = res.den / aux;
    res.num = res.num / aux;

    return res;

}

fraction mul (fraction a, fraction b){
    fraction res;
    res.num = a.num * b.num;
    res.den = a.den * b.den;
    int aux = gcd(res.den,res.num);
    res.den = res.den / aux;
    res.num = res.num / aux;

    if(res.den < 0){
        res.num *= -1;
        res.den *= -1;
    }

    return res;
}

int main(){
    return 0;
}