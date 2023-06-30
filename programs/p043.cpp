#include <iostream>
using namespace std;

 unsigned long hstr_to_integer(const char hstr[]) {
    unsigned long count = 0;

    for(int i=0; hstr[i] != '\0'; i++){

        if (hstr[i] >= '0' && hstr[i] <= '9') {
            count = (16*count) + (int(hstr[i]) - '0');
        }
        else if (hstr[i] >= 'A' && hstr[i] <= 'F') {
            count = (16*count) + (hstr[i] - 55);

        } else if (hstr[i] >= 'a' && hstr[i] <= 'f') {
            count = (16*count) + (hstr[i] - 87) ;
        }
    }
    return count;
}

int main() {
cout << hstr_to_integer("0") << endl;
cout << hstr_to_integer("A") << endl;
cout << hstr_to_integer("19") << endl;
cout << hstr_to_integer("fF") << endl;
cout << hstr_to_integer("CafeBabe2022") << endl;

    return 0;
}
