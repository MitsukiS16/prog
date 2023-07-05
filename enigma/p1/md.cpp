#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0, d = 0;
    cin >> n;
    cin >> x1 >> y1;

    while (n > 1)
    {
        cin >> x2 >> y2;
        int dx = x1 - x2, dy = y1 - y2;
        if (dx < 0)
            dx = -dx;
        if (dy < 0)
            dy = -dy;
        d += dx + dy;
        x1 = x2;
        y1 = y2;
        n--;
    }

    cout << d << endl;
    return 0;
}
