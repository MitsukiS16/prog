#include <iostream>
using namespace std;

int main() {
    int number = 0;
    int x1[50];
    int y1[50];
    int distance = 0;

    cin >> number;

    for(int i=0; i<number; i++) {
        cin >> x1[i];
        cin >> y1[i];

    }

    for (int i=1; i<number; i++) {
      
        distance += abs((x1[i-1] - x1[i]));
        distance += abs((y1[i-1] - y1[i]));

        //cout << "distance " << distance << endl;
    }

    cout << distance << endl;

    return 0;
}