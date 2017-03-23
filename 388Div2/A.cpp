#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << "\n";
        cout << "2";
        for (int i = 1; i < n / 2; i++)
            cout << " 2";
        cout << "\n";
    }
    else {
        n = n / 2 - 1;
        cout << n + 1 << "\n";
        cout << "3";
        for (int i = 0; i < n; i++)
            cout << " 2";
        cout << "\n";
    }
    return 0;
}
