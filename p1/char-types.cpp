#include <iostream>

using namespace std;

int main()
{
    int numberChar = 0;
    char ch = ' ';
    int countInteger = 0, countLetter = 0, countOthers = 0;
    cin >> numberChar;

    for (int i = 0; i < numberChar; i++)
    {
        cin >> ch;
        if (ch >= 'a' && ch <= 'z')
            countLetter++;
        else if (ch >= 'A' && ch <= 'Z')
            countLetter++;
        else if (ch >= '0' && ch <= '9')
            countInteger++;
        else
            countOthers++;
    }

    cout << countLetter << " " << countInteger << " " << countOthers << endl;
    return 0;
}