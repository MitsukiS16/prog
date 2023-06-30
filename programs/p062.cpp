#include <iostream>
#include <vector>
#include <string>
#include "print_string.h"

using namespace std;

void split(const string& s, vector<string>& v) {
    v.clear();
    string::size_type i = 0;
    while (i != s.size()) {
        while (i != s.size() && isspace(s[i]))  
            ++i;
        string::size_type j = i;
        while (j != s.size() && !isspace(s[j])) 
            ++j;
        if (i != j) {
            v.push_back(s.substr(i, j - i));   
            i = j;                             
        }
    }
}

int main() {


    { string s = "";
  vector<string> v;
  split(s, v);
  print(v); }

  { string s = "       C++        ";
  vector<string> v;
  split(s, v);
  print(v); }

    return 0;
}
