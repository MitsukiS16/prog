#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int k, d;
    cin >> k >> d;
    double approx = 0.0, x = 1.0;
    for (int i = 0; i <= k; i++)
    {
        approx += x / (2 * i + 1);
        x = -x;
    }
    approx *= 4;
    cout << fixed << setprecision(d) << approx << endl;
    return 0;
}