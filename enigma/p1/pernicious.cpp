#include <iostream>

using namespace std;

bool prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool pernicious(int n)
{
    // prime number os 1s in binary representation
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
            count++;
        n >>= 1;
    }
    return prime(count);
}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    for (int i = a; i < b; i++)
    {
        if (prime(i) && pernicious(i))
        {
            cout << i << " ";
        }
    }

    return 0;
}