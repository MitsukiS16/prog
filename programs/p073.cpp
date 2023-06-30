#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

#include "print.h"

using namespace std;

void uppercase(string& word) {
    for(long unsigned int i=0; i<word.length(); i++) {
        word[i]= toupper(word[i]);
    }
}


void normalise(const string& input_fname, const string& output_fname) {

    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;

    while(getline(in)) {
        line.erase(0,line.find_first_not_of(' '));
        line.erase(0,line.find_last_not_of(' ')+1);

        if(line.size() == 0) {
            //break;??
        }
        
        //if tamanho menor que 0, 
        //maior que zero escreov ficheiro

        out << uppercase(line) << endl;
    }

    

}



int main() {

{ normalise("p3_test1.txt", "p3_test1_out.txt"); 
  print("p3_test1_out.txt"); }
  cout << endl;
{ normalise("p3_test2.txt", "p3_test2_out.txt"); 
  print("p3_test2_out.txt"); }
    cout << endl;

{ normalise("p3_test3.txt", "p3_test3_out.txt"); 
  print("p3_test3_out.txt"); }
    cout << endl;

{ normalise("p3_test4.txt", "p3_test4_out.txt"); 
  print("p3_test4_out.txt"); }
    cout << endl;

{ normalise("p3_test5.txt", "p3_test5_out.txt"); 
  print("p3_test5_out.txt"); }

    return 0;
}   