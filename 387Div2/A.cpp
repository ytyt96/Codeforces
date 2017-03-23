#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a = sqrt(n), b;
    while (true) {
        if (n % a == 0) {
            b = n / a;
            break;
        }
        a--; 
    }
    cout << a << " " << b << "\n";
}
