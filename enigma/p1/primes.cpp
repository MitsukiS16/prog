#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j = 2;
        while (j < i && i % j != 0)
        {
            j++;
        }
        if (j == i)
            cout << j << " ";
    }

    return 0;
}