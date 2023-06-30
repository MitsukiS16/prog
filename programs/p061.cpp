#include <iostream>
#include <vector>
#include "smatrix.h"

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    r.clear();
    
    auto ita = a.begin(), itb = b.begin();
    
    while (ita != a.end() && itb != b.end()) {
        if (ita->row < itb->row || (ita->row == itb->row && ita->col < itb->col)) {
            r.push_back(*ita);
            ++ita;
        }
        else if (itb->row < ita->row || (ita->row == itb->row && itb->col < ita->col)) {
            r.push_back(*itb);
            ++itb;
        }
        else {
            int value = ita->value + itb->value;
            if (value != 0) {
                r.push_back({ita->row, ita->col, value});
            }
            ++ita;
            ++itb;
        }
    }
    
    while (ita != a.end()) {
        r.push_back(*ita);
        ++ita;
    }
    while (itb != b.end()) {
        r.push_back(*itb);
        ++itb;
    }
}

int main() {


{ smatrix r;
  sum({ },
      { {0, 3, 1}, {0, 50, 1} },
      r);
  print(r); }
{ smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
      r);
  print(r); }

    return 0;
}