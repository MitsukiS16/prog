#include <iostream>
#include <fstream>
#include <sstream>

#include "wc.h"


wcresult wc(const string& filename) {
    wcresult result = {0, 0, 0};

    string line, word;

    ifstream in(filename);

    while(getline(in, line)) {
        result.lines++;
        istringstream str(line);
        while(str >> word) {
            result.words++;
        }
        result.bytes += line.size() + 1 ;
    }


    return result;
}


int main() {

{ wcresult r = wc("p2_test1.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
{ wcresult r = wc("p2_test2.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
{ wcresult r = wc("p2_test3.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
{ wcresult r = wc("p2_test4.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
{ wcresult r = wc("p2_test5.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }

    return 0;
}   