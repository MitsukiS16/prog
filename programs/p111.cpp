#include <iostream>
#include <string>
#include <map>


using namespace std;

void replace(const map<char, char>& r, string& s) {
    for (long unsigned int i = 0; i < s.size(); i++) {
        if (r.find(s[i]) != r.end()) {
            s[i] = r.at(s[i]);
        }
    }
}

int main() {

{ string s = "C / C++ @ LEIC";
  replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
  cout << s << '\n'; }

{ string s = "C / C++ @ LEIC";
  replace({ }, s);
  cout << s << '\n'; } r43

{ string s = "A B C D E F";
  replace({ {' ', '_'}}, s);
  cout << s << '\n'; }

{ string s = "A B C D E F";
  replace({ {'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s);
  cout << s << '\n'; }

    return 0;
}