#include <iostream>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n;
    int countLetter = 0, countDigits = 0, countOthers = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c >= '0' && c <= '9')
        {
            countDigits++;
        }
        else if ((c >= 'a' && c <= 'z') ||
                 (c >= 'A' && c <= 'Z'))
        {
            countLetter++;
        }
        else
        {
            countOthers++;
        }
    }
    cout << countLetter << ' ' << countDigits << ' ' << countOthers << '\n';
    return 0;
}