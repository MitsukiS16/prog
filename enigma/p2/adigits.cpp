#include <iostream>

using namespace std;

int adigits(int a, int b, int c)
{
    int number = 0;
    if (a > b && a > c)
    {

        number = a * 10;

        if (b > c)
        {
            number = (number + b) * 10;
            number = number + c;
            cout << "number" << number << endl;
        }
        else
        {
            number = (number + c) * 10;
            number = number + b;
            cout << "number" << number << endl;
        }
    }
    else if (b > a && b > c)
    {
        number = b * 10;
        if (a > c)
        {
            number = (number + a) * 10;
            number = number + c;
            cout << "number" << number << endl;
        }
        else
        {
            number = (number + c) * 10;
            number = number + a;
            cout << "number" << number << endl;
        }
    }
    else
    {
        number = c * 10;

        if (a > b)
        {
            number = (number + a) * 10;
            number = number + b;
            cout << "number" << number << endl;
        }
        else
        {
            number = (number + b) * 10;
            number = number + a;
            cout << "number" << number << endl;
        }
    }
    return number;
}

int main()
{
    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';
    cout << adigits(3, 2, 1) << '\n';
    cout << adigits(3, 3, 3) << '\n';
    cout << adigits(10, 11, 12) << '\n';
    cout << adigits(100, 100, 100) << '\n';

    return 0;
}