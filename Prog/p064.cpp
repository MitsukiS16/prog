#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longest_prefix(const vector<string>& v) {
    int n = v.size();
    if (n == 0) {
        return "";
    }
    string prefix = v[0];
    for (int i = 1; i < n; i++) {
        while (v[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return "";
            }
        }
    }
    return prefix;
}

int main() {
    cout << "\"" << longest_prefix({ "apple", "apply", "ape", "april" }) << "\"\n";
    return 0;
}
