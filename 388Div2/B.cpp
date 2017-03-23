#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x1 *= 10;
    y1 *= 10;
    x2 *= 10;
    y2 *= 10;
    x3 *= 10;
    y3 *= 10;
    cout << "3\n";
    cout << ((x1 + x2) / 2 - x3 + (x1 + x2) / 2) / 10 << " " <<
            ((y1 + y2) / 2 - y3 + (y1 + y2) / 2) / 10 << "\n";
    cout << ((x1 + x3) / 2 - x2 + (x1 + x3) / 2) / 10 << " " <<
            ((y1 + y3) / 2 - y2 + (y1 + y3) / 2) / 10 << "\n";
    cout << ((x3 + x2) / 2 - x1 + (x3 + x2) / 2) / 10 << " " <<
            ((y3 + y2) / 2 - y1 + (y3 + y2) / 2) / 10 << "\n";
}
