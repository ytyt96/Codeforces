#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    int sol = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt += b[i];
    }

    if (cnt % 2 == 0)
        sol++;

    int v[n] = {0};

    int c = 0;
    for (int i = 0; i < n; i++)
        if (v[i] == 0) {
            v[i] = 1;
            c++;
            int po = p[i];
            while (v[po] == 0) {
                v[po] = 1;
                po = p[po];
            }
        }
    if (c > 1)
        sol += c; 

    cout << sol << "\n";
    return 0;
}
