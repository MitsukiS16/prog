#include <iostream>
#include <cmath>
#include "Operation.h"

using namespace std;

class Sum : public Operation {
    public: 
        Sum(int const op1, int const op2) : Operation(op1, op2) { }

        int operation() const {
            return get_op1() + get_op2();
        }
};

class Power : public Operation {
    public:
        Power(int op1, int op2) : Operation(op1, op2) { }
        int operation() const {
            return pow(get_op1() , get_op2() );
        }
};





int main() {
{ const Operation& s = Sum(2, 10); cout << s.operation() << ' '; 
  const Operation& p = Power(2, 10); cout << p.operation() << endl; }
{ Sum s(6, -2); cout << s.operation() << ' '; 
  Power p(-3, 0); cout << p.operation() << endl; }
{ Sum s(-6, 2); cout << s.operation() << ' '; 
  Power p(-2, 5); cout << p.operation() << endl; }
{ Sum s(-6, -2); cout << s.operation() << ' '; 
  Power p(2, 7); cout << p.operation() << endl; }
    return 0;
}