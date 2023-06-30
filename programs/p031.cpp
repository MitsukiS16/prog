#include <iostream>
using namespace std;

struct time_of_day {
    unsigned char h; // Hours [0,23]
    unsigned char m; // Minutes [0,59]
};



time_of_day tick(time_of_day t) {
    
}


int main() {
cout << tick({ 0, 0 }) << '\n';
cout << tick({ 12, 30 }) << '\n';
cout << tick({ 12, 59 }) << '\n';
cout << tick({ 23, 59 }) << '\n';
cout << tick(tick(tick({ 23, 59 }))) << '\n';

    return 0;
}