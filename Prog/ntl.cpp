#include <iostream>
using namespace std;

int nrl(const char s[], char low[])
{
    int alphabet[26]{0};
    for (int i = 0; i !='\0'; i++)
    {
        char letter = s[i];
        if (letter >= 'a' and letter <= 'z')
            alphabet[letter - 'a']++;
        if (letter >= 'A' and letter <= 'Z')
            alphabet[letter - 'A']++;
    }
    int nonRepeating = 0;
    int lowidx = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == 1)
        {
            low[lowidx] = char(i + 'a');
            nonRepeating++;
            lowidx++;
        }
    }
    if (nonRepeating == 0)
    {
        low[0] = '\0';
    }
    for (int i = 0; i < 27; i++)
    {
        if (low[i] == 0)
        {
            low[i] = '\0';
            break;
        }
    }
    return nonRepeating;
}

int main()
{
    const char s[] = "  F C U P  F E U P  Porto  ";
    char l[27] = {-1};
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
    return 0;
} 