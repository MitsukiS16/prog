#include <iostream>

using namespace std;

int count(const char str[]) {
    int count =0;
    while(str[count] != '\0') {
        count++;
    }
    return count;
}


char* repeat(const char str[], int n) {
    char *repetead = new char[5];
    int len = count(str);
    int index = 0;

    for(int i=0; i<len*n; i++) {
        if(index == len) {
            index = 0;
        }
        repetead[i] = str[index];
        index++;
    }
    repetead[len*n]='\0';

    return repetead;

}

int main() {
{ const char str[] = "H e l l o";
  char* r = repeat(str, 2);
  cout << "\"" << r << "\"\n";
  delete [] r; }
{ const char str[] = "C++";
  char* r = repeat(str, 1);
  cout << "\"" << r << "\"\n";
  delete [] r; }
{ const char str[] = "";
  char* r = repeat(str, 99);
  cout << "\"" << r << "\"\n";
  delete [] r; }
{ const char str[] = "C/C++@LEIC.";
  char* r = repeat(str, 5);
  cout << "\"" << r << "\"\n";
  delete [] r; }
{ const char str[] = "x";
  char* r = repeat(str, 15);
  cout << "\"" << r << "\"\n";
  delete [] r; }
    return 0;
}