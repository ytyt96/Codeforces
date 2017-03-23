#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, d;
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> m >> d;

    int col = 1;
    for (int i = 2; i <= months[m]; i++) {
        d += 1;
        if (d == 8) {
            d = 1;
            col++;
        }
    }
    cout << col << '\n';
        
    return 0;
}
