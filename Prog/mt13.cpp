#include <iostream>

using namespace std;

bool pangram(const char s[], char m[]){
    int alpha[26] {0};
    alpha[1] -> alpha + sizeof int
    int i=0;
    int result=0;

    while(s[i]!='\0'){
        if(s[i]>='a' && s[i]<='z')
            alpha[(s[i]-'a')]++;
        else if(s[i]>='A' && s[i]<='Z')
            alpha[(s[i]-'A')]++;
        i++;
    }

    for(int i=0; i<26; i++){
        if(alpha[i]==0){
            m[result]='a'+i;
            result++;
        }
    }

    m[result]='\0';

    for(int i=0; i<26; i++){
        if (alpha[i]==0)
            return false;
    }
    return true;
}

int main() {
{ char s[] = "";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" "
     << boolalpha << r << " \"" << m << "\"\n"; }
{ char s[] = "The quick brown fox jumps over the lazy dog";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
{ char s[] = "A quick brown fox jumps over a classy dog";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
{ char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
{ char s[] = " Stu yZ abC GhI MnO pQr   ";
  char m[27] = { -1 };
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }

    return 0;
}

