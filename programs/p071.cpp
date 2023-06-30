#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string lowercase(const string& str) {
    string result;
    for (char c : str) {
        result += tolower(c);
    }
    return result;
}


int count(const string& fname, const string& word) {
    int count = 0;
    string s;
    ifstream file(fname);

    while (file >> s) {
        if (lowercase(s) == lowercase(word)) {
            count++;
        }
    }
    return count;
}



int main() {
    cout << count("p1_test_a.txt", "THE") << '\n';
    cout << count("p1_test_a.txt", "0") << '\n';
    cout << count("p1_test_a.txt", "code") << '\n';
    cout << count("p1_test_b.txt", "Collider") << '\n';
    cout << count("p1_test_b.txt", "you") << '\n';
    
    return 0;
}