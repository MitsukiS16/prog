#include <iostream>

using namespace std;

void advance(int delta, int &d, int &m, int &y)
{
    
}

int main()
{
    {
        int d = 1, m = 1, y = 2022;
        advance(0, d, m, y);
        cout << d << ' ' << m << ' ' << y << endl;
    }

    {
        int d = 1, m = 10, y = 2022;
        advance(10, d, m, y);
        cout << d << ' ' << m << ' ' << y << endl;
    }

    {
        int d = 2, m = 6, y = 2022;
        advance(31, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }

    {
        int d = 2, m = 7, y = 2022;
        advance(31, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }

    {
        int d = 25, m = 2, y = 2000;
        advance(4, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }

    {
        int d = 25, m = 2, y = 2001;
        advance(4, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }

    {
        int d = 2, m = 12, y = 1900;
        advance(365 + 5, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }

    {
        int d = 31, m = 3, y = 1903;
        advance(365 + 366 + 30 + 5, d, m, y);
        cout << d << ' ' << m << ' ' << y << '\n';
    }
}